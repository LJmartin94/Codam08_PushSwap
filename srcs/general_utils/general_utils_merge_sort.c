/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils_merge_sort.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 18:54:23 by limartin      #+#    #+#                 */
/*   Updated: 2021/05/02 20:06:09 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

#include <stdio.h>
# define NRM "\x1B[0m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define ORNG "\x1B[33m"

int		ms_merge(t_sort *d, int first, int mid, int last)
{
	int store[mid + 1];
	int i;
	int l;
	int r;

	i = first;
	l = first;
	r = mid + 1;
	printf("Comparing indexes: %d - %d - %d\n", first, mid, last);
	// for (int j = 0; j < d->items; j++)
	// {
	// 	//printf("j: %d\n", j);
	// 	int *array;
	// 	array = *((int **)(d->to_sort));
	// 	printf("%d ", array[(d->ans)[j]]);
	// }
	// printf("\n");
	
	// while (i < last)
	// {
	// 	if (d->f(d, &(d->ans[l]), &(d->ans[r])) == l)
	// 	{
	// 		if ((r - (mid + 1)) > l)
	// 			d->ans[i] = store[(r - (mid + 1) - l)];
	// 		else
	// 			d->ans[i] = d->ans[l];
	// 		l++;
	// 		i++;
	// 	} 
	// 	else
	// 	{
	// 		if ((r - (mid + 1)) >= l)
	// 			store[(r - (mid + 1) - l)] = d->ans[l];
	// 		d->ans[i] = d->ans[r];
	// 		r++;
	// 		i++;
	// 	}
	// }
	
	for (int j = 0; j < d->items; j++)
	{
		int *array;
		array = *((int **)(d->to_sort));
		if (j == first)
			printf(GRN);
		if (j == mid + 1)
			printf(ORNG);
		printf("%d ", array[(d->ans)[j]]);
		if (j == last)
			printf(NRM);
	}
	printf("\n");
	return (0);
}

int		ms_split(t_sort *d, void *to_sort, int first, int last)
{
	int mid;

	mid = ((last - first) / 2) + first;
	if ((last - first) > 1)
	{
		ms_split(d, to_sort, first, mid);
		ms_split(d, to_sort, mid + 1, last);
	}
	if (first != last)
		ms_merge(d, first, mid, last);
	// else
	// {
	// 	printf("F: %d L: %d\n", first, last);
	// }
	return (0);
}

void 	*merge_sort(void *to_sort, int size, int len, int (*f)(t_sort *, void *, void *))
{
	t_sort	data;
	int		i;

	data.to_sort = to_sort;
	data.size = size;
	data.items = len;
	data.f = f;
	data.ans = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		data.ans[i] = i;
		i++;
	}
	ms_split(&data, to_sort, 0, len - 1);
	i = 0;
	while (i < len)
	{
		printf("%d ", data.ans[i]);
		i++;
	}
	printf("\n");

	// f(((unsigned char)to_sort + 0 * mem), ((unsigned char)to_sort + 1 * mem));
	return (to_sort);
}