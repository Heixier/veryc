/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:47:08 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/26 16:47:09 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

/**ra: shift up all elements of stack a by 1; first element becomes the last one
 * rb: shift up all elements of stack b by 1; first element becomes the last one
*/
void	ps_rotate(t_list **list_head, int method, int print)
{
	t_node	*to_move;

	if (method == STACK_A && print)
		ft_printf("ra\n");
	if (method == STACK_B && print)
		ft_printf("rb\n");
	if (!list_head || !*list_head || !(*list_head)-> head || \
!((*list_head)-> head -> next))
		return ;
	to_move = (*list_head)-> head;
	(*list_head)-> head = (*list_head)->head-> next;
	ps_lstadd_back(list_head, to_move);
	to_move -> next = NULL;
}

/**rr: ra and rb at the same time*/
void	rr(t_list **a_head, t_list **b_head)
{
	ps_rotate(a_head, STACK_A, 0);
	ps_rotate(b_head, STACK_B, 0);
	ft_printf("rr\n");
}

//**Basically just rotate the other direction; last becomes first*/
void	ps_rrotate(t_list **list_head, int method, int print)
{
	t_node	*traverse;
	t_node	*new_head;

	if (method == STACK_A && print)
		ft_printf("rra\n");
	if (method == STACK_B && print)
		ft_printf("rrb\n");
	if (!list_head || !*list_head || !(*list_head)-> head || \
!((*list_head)-> head -> next))
		return ;
	if (!((*list_head)-> head -> next -> next))
		return (ps_swap(list_head, method, 0));
	traverse = (*list_head)-> head;
	while (traverse -> next -> next)
		traverse = traverse -> next;
	new_head = traverse -> next;
	traverse -> next = NULL;
	new_head -> next = (*list_head)-> head;
	(*list_head)-> head = new_head;
}

void	rrr(t_list **a_head, t_list **b_head)
{
	ps_rrotate(a_head, STACK_A, 0);
	ps_rrotate(b_head, STACK_B, 0);
	ft_printf("rrr\n");
}
