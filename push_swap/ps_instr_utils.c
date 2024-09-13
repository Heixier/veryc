/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:45:02 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/11 17:45:03 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	copy_instr(t_instr *instr, t_instr *candidate)
{
	instr -> value = candidate -> value;
	instr -> position = candidate -> position;
	instr -> target = candidate -> target;
	instr -> a_up = candidate -> a_up;
	instr -> b_up = candidate -> b_up;
	instr -> a_down = candidate -> a_down;
	instr -> b_down = candidate -> b_down;
	instr -> moves = candidate -> moves;
	instr -> a_direction = candidate -> a_direction;
	instr -> b_direction = candidate -> b_direction;
}

void	reset_instr(t_instr *instr)
{
	instr -> value = 0;
	instr -> position = 0;
	instr -> target = 0;
	instr -> a_up = 0;
	instr -> a_down = 0;
	instr -> b_up = 0;
	instr -> b_down = 0;
	instr -> moves = 2147483647;
	instr -> a_direction = 0;
	instr -> b_direction = 0;
}

void	print_instr(t_instr *instr)
{
	ft_printf("\nINSTRUCTION SET\n");
	ft_printf("Value: %d\n", instr -> value);
	ft_printf("Position: %d\n", instr -> position);
	ft_printf("Target: %d\n", instr -> target);
	ft_printf("a_up: %d | b_up %d\n", instr -> a_up, instr -> b_up);
	ft_printf("a_down: %d | b_down %d\n", instr -> a_down, instr -> b_down);
	ft_printf("Moves: %d\n", instr -> moves);
	ft_printf("A_dir: %d | B_dir: %d\n", instr -> a_direction, \
	instr -> b_direction);
	if (instr -> a_direction == UP)
		ft_printf("a_direction: UP\n");
	else
		ft_printf("a_direction: DOWN\n");
	if (instr -> b_direction == UP)
		ft_printf("b_direction: UP\n\n");
	else
		ft_printf("b_direction: DOWN\n\n");
}

/** If they are going in the same direction, get the max val instead of total*/
void	max_movecount(t_instr *candidate, int best_a, int best_b)
{
	if (candidate -> a_direction == candidate -> b_direction)
	{
		if (candidate -> a_direction == UP)
		{
			if (candidate -> a_up >= candidate -> b_up)
				candidate -> moves = candidate -> a_up;
			else
				candidate -> moves = candidate -> b_up;
		}
		else
		{
			if (candidate -> a_down >= candidate -> b_down)
				candidate -> moves = candidate -> a_down;
			else
				candidate -> moves = candidate -> b_down;
		}
	}
	else
		candidate -> moves = best_a + best_b;
}
