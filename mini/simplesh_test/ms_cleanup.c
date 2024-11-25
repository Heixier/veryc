/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:09:36 by rsiah             #+#    #+#             */
/*   Updated: 2024/11/16 18:00:57 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

void	ms_cleanup(t_simp *simp)
{
	// (void)simp;
	printf("cleanup\n");
	ms_free_list(simp -> custom_builtins);
	// ft_free(simp);
}

void	ms_free_list(t_list *list)
{
	t_node	*traverse;
	t_node	*old_trav;

	traverse = list -> head;
	while (traverse)
	{
		old_trav = traverse;
		traverse = traverse -> next;
		ft_free(old_trav -> content);
		ft_free(old_trav);
	}
}