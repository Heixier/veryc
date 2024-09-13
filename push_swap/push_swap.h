/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:58 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/21 12:02:58 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define STACK_A 1
# define STACK_B 2
# define UP 1
# define DOWN 2
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_node
{
	int				n;
	struct s_node	*next;
}					t_node;

typedef struct s_list
{
	t_node	*head;
	int		size;
	int		min_val;
	int		min_pos;
	int		max_val;
	int		max_pos;
}			t_list;

typedef struct s_instr
{
	int	value;
	int	position;
	int	target;
	int	a_up;
	int	b_up;
	int	a_down;
	int	b_down;
	int	moves;
	int	a_direction;
	int	b_direction;
}				t_instr;

int			ps_check_error(int argc, char **argv);
t_node		*ps_make_node(int value);
int			ps_count_nodes(t_list **list);
void		ft_lstclear(t_list **lst);
void		ps_lstadd_back(t_list **lst, t_node *new);
void		ps_swap(t_list **list_head, int choice, int print);
void		ss(t_list **a_head, t_list **b_head);
long long	ps_atoll(const char *nptr);
int			ps_atoi(const char *nptr);
int			ps_strcmp(const char *s1, const char *s2);
t_list		*ps_new_list(int argc, char **argv);
void		ps_push(t_list **destination, t_list **source, int direction);
void		ps_rotate(t_list **list_head, int method, int print);
void		rr(t_list **a_head, t_list **b_head);
void		ps_rrotate(t_list **list_head, int method, int print);
void		rrr(t_list **a_head, t_list **b_head);
int			check_if_sorted(t_list **stack_head);
void		ps_begin_sort(int nodes, t_list **a_head, t_list **b_head);
void		sort_two(t_list **a_head);
void		rev_sort_two(t_list **b_head);
void		sort_three(t_list **a_head);
void		main_sort(t_list **a_head, t_list **b_head);
void		ps_refresh_lists(t_list **a_head, t_list **b_head);
void		ps_init_min_max(t_list **list);
void		ps_set_list_min_max(t_list **list);
void		ps_print_list(t_list **list);
void		ps_execute(t_instr *instr, t_list **a_head, t_list **b_head);
void		set_target_pos(t_instr *candidate, t_list **b_head);
void		set_movecount(t_instr *candidate, t_list **a_head, t_list **b_head);
void		set_value_and_pos(t_instr *candidate, t_node *item, int pos);
void		copy_instr(t_instr *instr, t_instr *candidate);
void		max_movecount(t_instr *candidate, int best_a, int best_b);
void		set_best_move(t_instr *instr, t_list **a_head, t_list **b_head);
void		reset_instr(t_instr *instr);
void		both_rotate_up(t_instr *instr, t_list **a_head, t_list **b_head);
void		both_rotate_down(t_instr *instr, t_list **a_head, t_list **b_head);
void		multi_rotate_up(t_list **list, int stack, int n);
void		multi_rotate_down(t_list **list, int stack, int n);
void		split_rotate(t_instr *instr, t_list **a_head, t_list **b_head);
void		ps_clean(t_list **a_head, t_list **b_head);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *str, size_t size);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *s);
char		**ps_split(char const *s, char c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		array_free(char **str_arr, int array_flag);
void		temp_print(t_list **a_head, t_list **b_head);
void		print_instr(t_instr *instr);

#endif
