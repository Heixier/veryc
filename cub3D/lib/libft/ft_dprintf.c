/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:14:22 by anteo             #+#    #+#             */
/*   Updated: 2024/11/21 18:19:59 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flush_buffer(t_buffer *buff, int fd)
{
	if (buff->buff_len > 0)
	{
		write(fd, buff->buffer, buff->buff_len);
		buff->print_len += buff->buff_len;
		buff->buff_len = 0;
	}
}

void	fill_buffer(t_buffer *buff, char c, int fd)
{
	if (buff->buff_len == BUFFER_SIZE - 1)
		flush_buffer(buff, fd);
	buff->buffer[buff->buff_len++] = c;
}

static int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

static void	format_util(const char *format, va_list args, int fd, t_buffer *buf)
{
	if (*format == 'c')
		fill_buffer(buf, (char)va_arg(args, int), fd);
	else if (*format == 's')
		myputstr_fd(va_arg(args, char *), fd, buf);
	else if (*format == 'p')
		myputptr(va_arg(args, void *), fd, buf);
	else if (*format == 'd' || *format == 'i')
		myputnbr_fd(va_arg(args, int), fd, buf);
	else if (*format == 'u')
		myputunbr_fd(va_arg(args, unsigned int), fd, buf);
	else if (*format == 'x')
		myputhex(va_arg(args, unsigned int), BASE_LOW, buf, fd);
	else if (*format == 'X')
		myputhex(va_arg(args, unsigned int), BASE_UPP, buf, fd);
	else if (*format == '%')
		fill_buffer(buf, '%', fd);
	else
	{
		fill_buffer(buf, '%', fd);
		fill_buffer(buf, *format, fd);
	}
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	t_buffer	buff;

	buff.print_len = 0;
	buff.buff_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*format && ft_isspace(*format))
				format++;
			if (*format)
				format_util(format, args, fd, &buff);
			else
				return (-1);
		}
		else
			fill_buffer(&buff, *format, fd);
		format++;
	}
	va_end(args);
	flush_buffer(&buff, fd);
	return (buff.print_len);
}
