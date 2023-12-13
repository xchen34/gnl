#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);


// char *read_and_update_line(int fd, char *saved_line);
// char *get_next_line(int fd);
// char *ft_free_and_nullify(char **ptr);
// char *concatenate_lines(char *line1, char *line2);
// char *extract_line(char *source, unsigned int start, size_t length);
// char *update_saved_line(char *saved_line, size_t new_start);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strdup(const char *s);
// size_t	ft_strlen(const char *s);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);


#endif