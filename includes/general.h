#ifndef GENERAL_H
# define GENERAL_H

#include <stddef.h>

int		*str_to_int_arrays(char **argv, int len);
int		ft_is_numeric(const char *str);
int		ft_atoi(const char *str);

int		get_next_line(int fd, char **line);

int		are_strs_eq(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif
