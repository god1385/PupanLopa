#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 
# endif

char	*get_next_line(int fd);
char	*ft_was_read(int fd, char *line);
char	*ft_strjoin(char  *s1, char  *s2);
int		finder(char *str);
size_t	ft_strlen(const char *str);
char	*ft_linehelper(char *line);
char	*ft_get_remain(char *remain);

#endif
