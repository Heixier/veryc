/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:45:43 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/26 15:45:44 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node NEW to the beginning of the list
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}
