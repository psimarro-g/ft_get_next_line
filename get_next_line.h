#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Open, read and write
# include <unistd.h>

//Malloc and free
# include <stdlib.h>

char	*get_next_line(int fd);

char	*create_line(int fd, char *saved);
char	*trim_saved(char *saved);
char	*save_remaining(char *saved);

char	*free_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
