/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:20:22 by rsiah             #+#    #+#             */
/*   Updated: 2025/01/11 12:39:52 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node NEW at the end of the list
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*list_traverser;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	list_traverser = *lst;
	while (list_traverser -> next)
		list_traverser = list_traverser -> next;
	list_traverser -> next = new;
}
