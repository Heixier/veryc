/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:29:41 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/26 17:29:54 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**If nodes are less than 2, does nothing*/
void	ps_begin_sort(int nodes, t_list **a_head, t_list **b_head)
{
	if (nodes < 2)
		return ;
	if (nodes == 2)
		sort_two(a_head);
	if (nodes == 3)
		sort_three(a_head);
	if (nodes > 3)
		main_sort(a_head, b_head);
}

void	sort_two(t_list **a_head)
{
	if (((*a_head)-> head -> n) > ((*a_head)-> head -> next -> n))
		ps_swap(a_head, STACK_A, 1);
}

void	rev_sort_two(t_list **b_head)
{
	if (((*b_head)->head -> n) < ((*b_head)-> head -> next -> n))
		ps_swap(b_head, STACK_B, 1);
}

/**
 * Unrolled bubble sort algorithm, updates values after each operation
 */
void	sort_three(t_list **a_head)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = (*a_head)-> head;
	second = first -> next;
	third = second -> next;
	if (first -> n > second -> n)
		ps_swap(a_head, STACK_A, 1);
	first = (*a_head)-> head;
	second = first -> next;
	third = second -> next;
	if (second -> n > third -> n)
		ps_rrotate(a_head, STACK_A, 1);
	first = (*a_head)-> head;
	second = first -> next;
	third = second -> next;
	if (first -> n > second -> n)
		ps_swap(a_head, STACK_A, 1);
}

int	check_if_sorted(t_list **stack_head)
{
	t_node	*traverse;

	if (!stack_head || !*stack_head || !(*stack_head)-> head)
		return (-1);
	traverse = (*stack_head)-> head;
	while (traverse -> next)
	{
		if (traverse -> n > traverse -> next -> n)
			return (0);
		traverse = traverse -> next;
	}
	return (1);
}
