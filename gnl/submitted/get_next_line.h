/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:11:18 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/30 12:11:20 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define BEFORE 2
# define AFTER 3

# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
char	*gnl_strndup(const char *s, size_t n);
char	*split_char(char *str, int option);
char	*make_remainder(int fd, char **remainder);
char	*read_error(char **remainder, char **chunk);

# ifndef MY_BLACK
#  define MY_BLACK "\033[0;30m"
# endif

# ifndef MY_RED
#  define MY_RED "\033[0;31m"
# endif

# ifndef MY_GREEN
#  define MY_GREEN "\033[0;32m"
# endif

# ifndef MY_BLUE
#  define MY_MY_BLUE "\033[0;34m"
# endif

# ifndef MY_PURPLE
#  define MY_PURPLE "\033[0;35m"
# endif

# ifndef MY_CYAN
#  define MY_CYAN "\033[0;36m"
# endif

# ifndef MY_LIGHT_RED
#  define MY_LIGHT_RED "\033[1;31m"
# endif

# ifndef MY_LIGHT_GREEN
#  define MY_LIGHT_GREEN "\033[1;32m"
# endif

# ifndef MY_LIGHT_BLUE
#  define MY_LIGHT_BLUE "\033[1;34m"
# endif

# ifndef MY_LIGHT_PURPLE
#  define MY_LIGHT_PURPLE "\033[1;35m"
# endif

# ifndef MY_LIGHT_CYAN
#  define MY_LIGHT_CYAN "\033[1;36m"
# endif

# ifndef MY_BOLD
#  define MY_BOLD "\033[1m"
# endif

# ifndef MY_UNDERLINE
#  define MY_UNDERLINE "\033[4m"
# endif

# ifndef MY_BLINK
#  define MY_BLINK "\033[5m"
# endif

# ifndef MY_END
#  define MY_END "\033[0m"
# endif

#endif