/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:35 by rsiah             #+#    #+#             */
/*   Updated: 2024/11/23 18:44:07 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and every successor of that node
 * using the function DEL and free.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_node **lst, void (*del)(void **))
{
	t_node	*traverser;
	t_node	*list_holder;

	traverser = *lst;
	if (lst)
	{
		while (traverser)
		{
			list_holder = traverser;
			traverser = traverser -> next;
			del(&list_holder -> content);
			ft_free((void **)&list_holder);
		}
		(*lst) = NULL;
	}
}
