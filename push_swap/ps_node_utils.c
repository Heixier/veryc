/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:03:03 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/21 12:03:05 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * This function uses malloc. Do not call this function without assignment
 */
t_node	*ps_make_node(int value)
{
	t_node	*output;

	output = malloc(sizeof(t_node));
	if (output)
	{
		output -> next = NULL;
		output -> n = value;
	}
	return (output);
}

/**
 * Adds the node NEW at the end of the list
 */
void	ps_lstadd_back(t_list **lst, t_node *new)
{
	t_node	*list_traverser;

	if (!lst || !new || !*lst)
		return ;
	if (!(*lst)-> head)
	{
		(*lst)-> head = new;
		return ;
	}
	list_traverser = (*lst)-> head;
	while (list_traverser -> next)
		list_traverser = list_traverser -> next;
	list_traverser -> next = new;
}

/**Returns the number of nodes in the list*/
int	ps_count_nodes(t_list **list)
{
	int		output;
	t_node	*traverse;

	if (!list || !*list || !(*list)-> head)
		return (0);
	output = 1;
	traverse = (*list)-> head;
	while (traverse -> next)
	{
		traverse = traverse -> next;
		output++;
	}
	return (output);
}

void	ps_init_min_max(t_list **list)
{
	(*list)-> max_val = (*list)-> head -> n;
	(*list)-> min_val = (*list)-> head -> n;
	(*list)-> max_pos = 0;
	(*list)-> min_pos = 0;
}

void	temp_print(t_list **a_head, t_list **b_head)
{
	ft_printf("Stack A (Count: %d) | (Min: %d @ %d) | (Max: %d @ %d)\n", \
	ps_count_nodes(a_head), (*a_head)-> min_val, (*a_head)-> min_pos, \
	(*a_head)-> max_val, (*a_head)-> max_pos);
	ps_print_list(a_head);
	ft_printf("Stack B (Count: %d) | (Min: %d @ %d) | (Max: %d @ %d)\n", \
	ps_count_nodes(b_head), (*b_head)-> min_val, (*b_head)-> min_pos, \
	(*b_head)-> max_val, (*b_head)-> max_pos);
	ps_print_list(b_head);
}
