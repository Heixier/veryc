/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:23:17 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/22 16:23:18 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_node	*traverse;
	t_node	*holder;

	if (!lst || !*lst)
		return ;
	traverse = (*lst)-> head;
	while (traverse)
	{
		holder = traverse -> next;
		free(traverse);
		traverse = holder;
	}
	free(*lst);
	(*lst) = NULL;
}

/**
 * Creates a new list and initialises it with nodes 
 */
t_list	*ps_new_list(int argc, char **argv)
{
	t_list	*output;
	t_node	*node;
	int		pos;

	pos = 0;
	output = malloc(sizeof(t_list));
	if (!output)
		return (NULL);
	if (!argv || !*argv)
		output -> head = NULL;
	else
	{
		output -> head = NULL;
		while (pos < argc)
		{
			node = ps_make_node((int)ps_atoll(argv[pos]));
			ps_lstadd_back(&output, node);
			pos++;
		}
	}
	return (output);
}

/** Call this function before pushing anything from A*/
void	ps_set_list_min_max(t_list **list)
{
	int		pos;
	t_node	*traverse;

	pos = 0;
	traverse = (*list)-> head;
	if (!traverse)
		return ;
	ps_init_min_max(list);
	while (traverse)
	{
		if (traverse -> n > (*list)-> max_val)
		{
			(*list)-> max_pos = pos;
			(*list)-> max_val = traverse -> n;
		}
		if (traverse -> n < (*list)-> min_val)
		{
			(*list)-> min_pos = pos;
			(*list)-> min_val = traverse -> n;
		}
		traverse = traverse -> next;
		pos++;
	}
}

/** Recalculates the size of each list*/
void	ps_refresh_lists(t_list **a_head, t_list **b_head)
{
	(*a_head)-> size = ps_count_nodes(a_head);
	(*b_head)-> size = ps_count_nodes(b_head);
	ps_set_list_min_max(a_head);
	ps_set_list_min_max(b_head);
}

void	ps_print_list(t_list **list)
{
	t_node	*traverse;
	int		position;

	if (!(*list)-> head)
		return ;
	traverse = (*list)-> head;
	position = 0;
	while (traverse)
	{
		ft_printf("Node: %d | Value: %d\n", position, traverse -> n);
		position++;
		traverse = traverse -> next;
	}
}
