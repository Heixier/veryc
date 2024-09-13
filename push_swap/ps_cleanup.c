/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:56:28 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/11 17:56:29 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	push_all_back(t_list **dest, t_list **src)
{
	while ((*src)-> head)
		ps_push(dest, src, STACK_A);
}

void	max_on_top(t_list **list)
{
	int	dist_up;
	int	dist_down;

	dist_up = (*list)->max_pos;
	dist_down = (*list)-> size - (*list)-> max_pos;
	if (dist_up <= dist_down)
	{
		while (dist_up--)
			ps_rotate(list, STACK_B, 1);
	}
	else
	{
		while (dist_down--)
			ps_rrotate(list, STACK_B, 1);
	}
}

void	ps_clean(t_list **a_head, t_list **b_head)
{
	ps_refresh_lists(a_head, b_head);
	max_on_top(b_head);
	push_all_back(a_head, b_head);
}
