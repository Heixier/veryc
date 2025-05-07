/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:11:59 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/26 16:11:59 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of nodes in the list
 * 
 * @param lst 
 * @return int 
 */
int	ft_lstsize(t_node *lst)
{
	size_t	count;
	t_node	*traverse;

	count = 0;
	if (lst)
	{
		count = 1;
		traverse = lst;
		while (traverse -> next)
		{
			count++;
			traverse = traverse -> next;
		}
	}
	return (count);
}
