/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:14:15 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/26 16:14:16 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last node of the list
 * 
 * @param lst 
 * @return t_node* 
 */
t_node	*ft_lstlast(t_node *lst)
{
	if (lst)
		while (lst -> next)
			lst = lst -> next;
	return (lst);
}
