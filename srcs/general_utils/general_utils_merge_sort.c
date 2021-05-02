/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils_merge_sort.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 18:54:23 by limartin      #+#    #+#                 */
/*   Updated: 2021/05/02 16:39:47 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

typedef struct s_sort
{
	int	*ans;
	int size;
	int items;
	int (*f)(void *, void *);
}	t_sort;

#include <stdio.h>

int		ms_split(t_sort *d, void *to_sort, int first, int last)
{
	int mid;

	if ((last - first) > 1)
	{
		mid = ((last - first) / 2) + first;
		ms_split(d, to_sort, first, mid);
		ms_split(d, to_sort, mid + 1, last);
	}
	else
	{
		printf("F: %d L: %d\n", first, last);
	}
	return (0);
}

void 	*merge_sort(void *to_sort, int size, int len, int (*f)(void *, void *))
{
	t_sort data;

	data.size = size;
	data.items = len;
	data.f = f;
	ms_split(&data, to_sort, 0, len - 1);



	// f(((unsigned char)to_sort + 0 * mem), ((unsigned char)to_sort + 1 * mem));
	return (to_sort);
}