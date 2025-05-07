/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:12:00 by rsiah             #+#    #+#             */
/*   Updated: 2025/03/05 19:38:47 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Frees and NULLs a pointer*/
void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/*Frees a string array*/
void	ft_free_arr(char ***ptr)
{
	int	i;

	if (!ptr || !*ptr)
		return ;
	i = 0;
	while ((*ptr)[i])
	{
		free((*ptr)[i]);
		(*ptr)[i] = NULL;
		i++;
	}
	free(*ptr);
	*ptr = NULL;
}

/*Closes a valid fd and sets it to -1*/
void	ft_close(int *fd)
{
	if (*fd != -1)
		close(*fd);
	*fd = -1;
}
