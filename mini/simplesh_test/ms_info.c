/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:18:21 by rsiah             #+#    #+#             */
/*   Updated: 2024/11/16 17:31:59 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

// Print string list
void	ms_print_slist(t_list *list)
{
	t_node	*traverse;

	traverse = list -> head;
	while (traverse)
	{
		printf("%s\n", (char *)traverse -> content);
		traverse = traverse -> next;
	}
}

void	ms_print_sarray(char **array)
{
	int	i;
	
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}