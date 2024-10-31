/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:12:00 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:12:02 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Frees and NULLs*/
void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

/*Frees a string array*/
void	ft_free_arr(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

/*Closes a valid fd and sets it to -1*/
void	ft_close(int fd)
{
	if (fd != -1)
		close(fd);
	fd = -1;
}
