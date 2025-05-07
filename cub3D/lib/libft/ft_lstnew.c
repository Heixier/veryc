/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:30:16 by rsiah             #+#    #+#             */
/*   Updated: 2024/11/25 20:07:52 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**Returns a new node for the list (uses malloc);
*/
t_node	*ft_lstnew(void *content)
{
	t_node	*output;

	output = ft_calloc(sizeof(t_node), 1);
	if (output)
	{
		output -> next = NULL;
		output -> prev = NULL;
		output -> content = ft_strdup(content);
		if (!output -> content)
			return (perror("malloc"), NULL);
	}
	return (output);
}
