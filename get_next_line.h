
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

// get_next_line
char    *get_next_line(int fd);
char    *ft_substr(char const *s, unsigned int start, size_t len);

// get_next_line_utils
char    *ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *s, int c);

#endif
