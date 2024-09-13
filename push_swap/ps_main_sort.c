/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:40:16 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/29 15:40:33 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ps_execute(t_instr *instr, t_list **a_head, t_list **b_head)
{
	set_best_move(instr, a_head, b_head);
	if (instr -> moves != 0)
	{
		if (instr -> a_direction == UP && instr -> b_direction == UP)
			both_rotate_up(instr, a_head, b_head);
		else if (instr -> a_direction == DOWN && instr -> b_direction == DOWN)
			both_rotate_down(instr, a_head, b_head);
		else
			split_rotate(instr, a_head, b_head);
	}
	ps_push(b_head, a_head, STACK_B);
	reset_instr(instr);
}

//* Let's sort */
void	main_sort(t_list **a_head, t_list **b_head)
{
	t_instr	*instr;

	instr = malloc(sizeof(t_instr));
	if (!instr)
		return ;
	if (check_if_sorted(a_head))
	{
		free(instr);
		return ;
	}
	ps_push(b_head, a_head, STACK_B);
	reset_instr(instr);
	ps_refresh_lists(a_head, b_head);
	while ((*a_head)-> head -> next)
	{
		ps_refresh_lists(a_head, b_head);
		ps_execute(instr, a_head, b_head);
	}
	ps_clean(a_head, b_head);
	free(instr);
}
