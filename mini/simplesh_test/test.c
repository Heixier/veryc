/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:06:21 by rsiah             #+#    #+#             */
/*   Updated: 2024/11/20 22:11:34 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_libft/libft.h"

void	print_array(char **arr)
{
	int i = 0;

	if (!arr)
		return ;
	while (arr[i])
	{
		ft_dprintf(1, "%d: %s\n", i, arr[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	char **arr;

	arr = ft_split(argv[1], " ");
	print_array(arr);
	ft_free_arr(&arr);
	return (0);
}