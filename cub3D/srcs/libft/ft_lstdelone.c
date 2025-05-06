/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:25:11 by rsiah             #+#    #+#             */
/*   Updated: 2025/01/18 15:03:06 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Takes as a parameter a node and frees the memory of the node's content 
 * using the function DEL given as a parameter and free the node.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstdelone(t_node *lst, void (*del)(void *))
{
	if (lst && del)
		del(lst -> content);
	ft_free((void **)&lst);
}
