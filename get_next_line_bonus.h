/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:50:38 by psimarro          #+#    #+#             */
/*   Updated: 2022/06/13 19:50:40 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//Open, read and write
# include <unistd.h>

//Malloc and free
# include <stdlib.h>

//Using INT_MAX and INT_MIN
# include <limits.h>

char	*get_next_line(int fd);

char	*get_line(int fd, char *buff);
char	*trim_line(char *buff);
char	*save_rest(char *buff);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_free_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
