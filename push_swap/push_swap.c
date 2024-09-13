/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:24 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/21 12:02:27 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] != c && (s[i + 1] == c || !(s[i + 1])))
				count++;
			i++;
		}
	}
	return (count);
}

char	**set_array(char **argv, int array_flag)
{
	char	**output;

	if (array_flag == 1)
		output = ps_split(argv[1], ' ');
	else
		output = &argv[1];
	return (output);
}

int	get_items(int argc, char **argv, int array_flag)
{
	int	output;

	if (array_flag == 1)
		output = count_words(argv[1], ' ');
	else
		output = argc - 1;
	return (output);
}

void	display_error(void)
{
	ft_printf("Error");
	write(2, "\n", 2);
}

int	main(int argc, char **argv)
{
	t_list	*a_head;
	t_list	*b_head;
	int		items;
	int		arr_flag;
	char	**num_array;

	if (argc == 2)
		arr_flag = 1;
	else
		arr_flag = 0;
	num_array = set_array(argv, arr_flag);
	items = get_items(argc, argv, arr_flag);
	if (ps_check_error(items, num_array))
		return (array_free(num_array, arr_flag), display_error(), -1);
	a_head = ps_new_list(items, num_array);
	b_head = ps_new_list(items, NULL);
	if (!a_head || !b_head)
		return (array_free(num_array, arr_flag), -1);
	ps_begin_sort(items, &a_head, &b_head);
	return (array_free(num_array, arr_flag), \
	ft_lstclear(&a_head), ft_lstclear(&b_head), 0);
}
