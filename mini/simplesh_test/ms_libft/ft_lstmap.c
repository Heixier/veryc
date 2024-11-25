/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:56:41 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/28 11:56:42 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Accounts for when content is malloc'd 
 * 
 * @param content 
 * @param lst 
 * @param del 
 */
void	del_content(void *content, t_node **lst, void (*del)(void *))
{
	free(content);
	ft_lstclear(lst, del);
}

/**
 * @brief Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed	
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_node* 
 */
t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_node	*input_traverser;
	t_node	*output;
	t_node	*output_traverser;
	void	*content_holder;

	if (!f || !del || !lst)
		return (NULL);
	content_holder = f(lst -> content);
	output = ft_lstnew(content_holder);
	if (!output)
		return (del(content_holder), NULL);
	output_traverser = output;
	input_traverser = lst -> next;
	while (input_traverser)
	{
		content_holder = f(input_traverser -> content);
		output_traverser -> next = ft_lstnew(content_holder);
		if (!output_traverser -> next)
			return (del_content(content_holder, &output, del), NULL);
		input_traverser = input_traverser -> next;
		output_traverser = output_traverser -> next;
	}
	return (output);
}

// This one just tests my del_content function
//
// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	char *test_str = strdup(argv[1]);
// 	printf("Current string: %s\n", test_str);
// 	del_content(test_str);
// 	if (!test_str)
// 		printf("Content deleted!\n");
// 	else
// 		printf("Content remaining: %s\n", test_str);
// 	return (0);
// }