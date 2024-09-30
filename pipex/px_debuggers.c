/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_debuggers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:35 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/23 14:29:36 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printfd.h"
#include "pipex.h"

void	print_array(char **array, char *desc)
{
	int	i;

	i = 0;
	if (!array)
		ft_printfd(1, "%s array is NULL!\n", desc);
	else if (!array[i])
		ft_printfd(1, "%s array is empty\n", desc);
	else
	{
		while (array[i])
			(ft_printfd(1, "%s [%d]: %s\n", desc, i, array[i]), i++);
		ft_printfd(1, "\n");
	}
}

/** Refer to header file for values*/
void	print_struct(t_px *px)
{
	print_array(px -> argv, "ARGV");
	print_array(px -> paths, "PATHS");
	print_array(px -> cmd1, "CMD1");
	print_array(px -> cmd2, "CMD2");
}
