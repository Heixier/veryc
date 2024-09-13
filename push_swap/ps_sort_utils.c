/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:49:03 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/11 17:49:10 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/** Regular ra rb rr is rotate up. It's confusing, I know*/
void	both_rotate_up(t_instr *instr, t_list **a_head, t_list **b_head)
{
	int	a_credit;
	int	b_credit;

	a_credit = instr -> a_up;
	b_credit = instr -> b_up;
	while (a_credit > 0 && b_credit > 0)
	{
		rr(a_head, b_head);
		a_credit--;
		b_credit--;
	}
	while (a_credit > 0)
	{
		a_credit--;
		ps_rotate(a_head, STACK_A, 1);
	}
	while (b_credit > 0)
	{
		ps_rotate(b_head, STACK_B, 1);
		b_credit--;
	}
}

void	both_rotate_down(t_instr *instr, t_list **a_head, t_list **b_head)
{
	int	a_credit;
	int	b_credit;

	a_credit = instr -> a_down;
	b_credit = instr -> b_down;
	while (a_credit > 0 && b_credit > 0)
	{
		rrr(a_head, b_head);
		a_credit--;
		b_credit--;
	}
	while (a_credit > 0)
	{
		ps_rrotate(a_head, STACK_A, 1);
		a_credit--;
	}
	while (b_credit > 0)
	{
		ps_rrotate(b_head, STACK_B, 1);
		b_credit--;
	}
}

void	multi_rotate_up(t_list **list, int stack, int n)
{
	if (!n)
		return ;
	while (n--)
		ps_rotate(list, stack, 1);
}

void	multi_rotate_down(t_list **list, int stack, int n)
{
	if (!n)
		return ;
	while (n--)
		ps_rrotate(list, stack, 1);
}

void	split_rotate(t_instr *instr, t_list **a_head, t_list **b_head)
{
	if (instr -> a_direction == UP)
		multi_rotate_up(a_head, STACK_A, instr -> a_up);
	else
		multi_rotate_down(a_head, STACK_A, instr -> a_down);
	if (instr -> b_direction == UP)
		multi_rotate_up(b_head, STACK_B, instr -> b_up);
	else
		multi_rotate_down(b_head, STACK_B, instr -> b_down);
}
