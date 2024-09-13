/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:38:46 by rsiah             #+#    #+#             */
/*   Updated: 2024/06/18 16:38:46 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	pf_putchar(unsigned char c);
int	pf_putstring(char *str);
int	pf_putaddr(void *ptr);
int	pf_putnbr(int n);
int	pf_putnbr_u(unsigned int n);
int	pf_puthex(unsigned int hexa, int upper);

#endif
