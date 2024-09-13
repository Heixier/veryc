/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:36 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/21 12:02:38 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**Swap a: Swap the first 2 elements at the top of stack a*
 * Do nothing if there's only one element*/
void	ps_swap(t_list **list_head, int method, int print)
{
	t_node	*current_node;
	t_node	*next_node;

	if (method == STACK_A && print)
		ft_printf("sa\n");
	if (method == STACK_B && print)
		ft_printf("sb\n");
	if (!list_head || !*list_head || !((*list_head)-> head) || \
!(*list_head)-> head -> next)
		return ;
	current_node = (*list_head)-> head;
	next_node = current_node -> next;
	current_node -> next = next_node -> next;
	next_node -> next = current_node;
	(*list_head)-> head = next_node;
	return ;
}

/**ss: swap A and B at the same time, only printing ss*/
void	ss(t_list **a_head, t_list **b_head)
{
	ps_swap(a_head, STACK_A, 0);
	ps_swap(b_head, STACK_B, 0);
	ft_printf("ss\n");
}

/**pa: push from top of b to top of a; do nothing if b is empty
 * pb: push from top of a to top of b; do nothing if a is empty
*/
void	ps_push(t_list **dest_list, t_list **src_list, int direction)
{
	t_node	*to_move;
	t_node	*original_head;
	t_node	*new_src_head;

	if (direction == STACK_A)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	if (!(*src_list) || !(*dest_list) || !((*src_list)-> head))
		return ;
	new_src_head = (*src_list)-> head -> next;
	to_move = (*src_list)-> head;
	original_head = (*dest_list)-> head;
	to_move -> next = original_head;
	(*dest_list)-> head = to_move;
	(*src_list)-> head = new_src_head;
}
