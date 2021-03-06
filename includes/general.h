/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:15:32 by lindsay       #+#    #+#                 */
/*   Updated: 2021/05/03 18:03:31 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include <stddef.h>
# include <stdlib.h>
# include "switch_case.h"

typedef struct s_sort
{
	void	*to_sort;
	int		*ans;
	int		size;
	int		items;
	int		(*f)(struct s_sort *, void *, void *);
} t_sort;

int		*str_to_int_arrays(char **strs, int len);
int		ft_is_numeric(const char *str);
int		mod_ft_atoi(const char *str);

char	**int_array_to_strs(int *array, int len);
char	*ft_itoa(int n);

int		get_next_line(int fd, char **line);

int		are_strs_eq(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

void 	*merge_sort(void *to_sort, int size, int len, int (*f)(t_sort *, void *, void *));

#endif
