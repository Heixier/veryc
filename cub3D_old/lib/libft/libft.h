/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:43:05 by anteo             #+#    #+#             */
/*   Updated: 2025/04/10 21:24:42 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

# define BASE_LOW "0123456789abcdef"
# define BASE_UPP "0123456789ABCDEF"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_list
{
	t_node	*head;
}				t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char *seps);
char		*ft_itoa(int n);

// bonuses
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);

// lists
t_node		*ft_lstnew(void *content);
void		ft_lstadd_back(t_node **lst, t_node *new);
void		ft_lstadd_front(t_node **lst, t_node *new);
void		ft_lstdelone(t_node *lst, void (*del)(void *));
t_node		*ft_lstlast(t_node *lst);
int			ft_lstsize(t_node *lst);
void		ft_lstclear(t_node **lst, void (*del)(void **));
void		ft_lstiter(t_node *lst, void (*f)(void *));
t_node		*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void **));

// dprintf

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	int		buff_len;
	int		print_len;
}	t_buffer;

void		flush_buffer(t_buffer *buff, int fd);
void		fill_buffer(t_buffer *buff, char c, int fd);
int			ft_dprintf(int fd, const char *format, ...);
void		myputnbr_fd(int n, int fd, t_buffer *buff);
void		myputunbr_fd(unsigned int n, int fd, t_buffer *buff);
void		myputstr_fd(char *s, int fd, t_buffer *buff);
void		myputptr(void *ptr, int fd, t_buffer *buff);
void		myputchar_fd(char c, int fd, int *print_len);
void		myputhex(unsigned long long hex, \
char *base, t_buffer *buff, int fd);

// GNL
void		*gnl_free(void **buffer, void **buffer2);
char		*get_next_line(int fd);
char		*gnl_strchr(const char *s, int c);
char		*gnl_substr(const char *s, unsigned int start, size_t len);
char		*gnl_strjoin(const char *s1, const char *s2);

//add-ons

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strccmp(const char *s1, const char *s2, char c);
int			ft_whitespace(int c);
char		*ft_strjoinfree(char *s1, char *s2);
char		*ft_strndup(char *str, size_t n);
int			ft_count_to_c(char *str, char c);
char		*ft_str_realloc(char *str, size_t size);
int			ft_strarrlen(char **arr);
char		*split_to_char(char *str, char c);
int			ft_aredigits(char *str);
int			ft_arealphas(char *str);
int			ft_arealnums(char *str);
long long	ft_atoll(const char *nptr);

// cleanup
void		ft_free(void **ptr);
void		ft_free_arr(char ***ptr);
void		ft_close(int *fd);

#endif
