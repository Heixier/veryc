/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:30:16 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/26 15:30:16 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocates with malloc and returns a new node. 
 * The member variable
 * CONTENT is initialised with the value of parameter CONTENT. 
 * The variable NEXT is initialised to NULL; (uses malloc)
 * 
 * @param content 
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*output;

	output = malloc(sizeof(t_list));
	if (output)
	{
		output -> next = NULL;
		output -> content = content;
	}
	return (output);
}
