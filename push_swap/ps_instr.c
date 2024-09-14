/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:48:37 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/10 14:48:39 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	get_target_pos(int value, t_list **b_head)
{
	int		target_pos;
	int		highest_num;
	t_node	*traverse;

	target_pos = 0;
	highest_num = INT_MIN;
	traverse = (*b_head)-> head;
	while (traverse)
	{
		if (traverse -> n < value && traverse -> n > highest_num)
			highest_num = traverse -> n;
		traverse = traverse -> next;
	}
	traverse = (*b_head)-> head;
	while (traverse)
	{
		if (traverse -> n == highest_num)
			break ;
		target_pos++;
		traverse = traverse -> next;
	}
	if (highest_num == INT_MIN)
		target_pos = (*b_head)-> max_pos;
	return (target_pos);
}

/** Insta crash if traverse is NULL*/
void	set_target_pos(t_instr *candidate, t_list **b_head)
{
	int		value;
	int		target_pos;

	value = candidate -> value;
	target_pos = get_target_pos(value, b_head);
	candidate -> target = target_pos;
}

/** Sets movecounts and optimal direction*/
void	set_movecount(t_instr *candidate, t_list **a_head, t_list **b_head)
{
	int	best_a;
	int	best_b;

	candidate -> a_up = candidate -> position;
	candidate -> b_up = candidate -> target;
	candidate -> a_down = (*a_head)-> size - candidate -> position;
	candidate -> b_down = (*b_head)-> size - candidate -> target;
	best_a = candidate -> a_up;
	best_b = candidate -> b_up;
	if (candidate -> a_up <= candidate -> a_down)
		candidate -> a_direction = UP;
	else
	{
		candidate -> a_direction = DOWN;
		best_a = candidate -> a_down;
	}
	if (candidate -> b_up <= candidate -> b_down)
		candidate -> b_direction = UP;
	else
	{
		candidate -> b_direction = DOWN;
		best_b = candidate -> b_down;
	}
	max_movecount(candidate, best_a, best_b);
}

/** Set up position and value for item in stack A*/
void	set_value_and_pos(t_instr *candidate, t_node *item, int pos)
{
	candidate -> value = item -> n;
	candidate -> position = pos;
}

//** Compares each t_instr to find best instr*/
void	set_best_move(t_instr *instr, t_list **a_head, t_list **b_head)
{
	t_node	*traverse;
	t_instr	*candidate;
	int		pos;

	pos = 0;
	candidate = malloc(sizeof(t_instr));
	if (!candidate)
		return ;
	traverse = (*a_head)-> head;
	while (traverse)
	{
		reset_instr(candidate);
		set_value_and_pos(candidate, traverse, pos);
		set_target_pos(candidate, b_head);
		set_movecount(candidate, a_head, b_head);
		if (candidate -> moves < instr -> moves)
			copy_instr(instr, candidate);
		pos++;
		traverse = traverse -> next;
	}
	free(candidate);
}
