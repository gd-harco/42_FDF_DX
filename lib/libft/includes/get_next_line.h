/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:11:05 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/07 22:36:57 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

char	*get_next_line(int fd);
int		index_of(char buf[BUFFER_SIZE +1], char r);
size_t	ft_strlen(const char	*s);
char	*gnl_join(char *str, char buff[BUFFER_SIZE + 1], size_t	len);
void	move_buf(char buf[BUFFER_SIZE + 1], size_t index);
char	*final_read(char buf[BUFFER_SIZE + 1], \
		int reading, char *str);
char	*joined(char buf[BUFFER_SIZE + 1], char *str);
#endif
