/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils_merge_sort.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 18:54:23 by limartin      #+#    #+#                 */
/*   Updated: 2021/05/14 01:18:26 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

#include <stdio.h>
# define NRM "\x1B[0m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define ORNG "\x1B[33m"

static int debug_print(t_sort *d, int first, int mid, int last)
{
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

static int	swap_ints(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
	return (0);
}

ops_ms_merge(t_sort *d, int first, int mid, int last)
{
	int *patch;
	int p_len;
	int p_index;
	int i;
	int r;

	i = first;
	mid++;
	r = mid;
	patch = (int *)malloc(sizeof(int) * (mid));
	p_len = 0;
	p_index = 0;
	while (i < r && r <= last)
	{
		if (p_len == 0 && (d->f(d, &(d->ans[i]), &(d->ans[r])) == d->ans[i]))
			i++;
		else if (p_len > 0 && d->f(d, &(patch[p_index]), &(d->ans[r])) == patch[p_index])
		{
			if (p_len < mid)
			{
				patch[p_len] = d->ans[i];
				p_len++;
			}
			d->ans[i] = patch[p_index];
			p_index++;
			i++;
		}
		else
		{
			if (p_len < mid)
			{
				patch[p_len] = d->ans[i];
				p_len++;
			}
			d->ans[i] = d->ans[r];
			r++;
			i++;
		}
	}
	printf("DEBUG: p_inx: %d, p_len: %d, i: %d, r: %d\n", p_index, p_len, i, r);
	while (p_index < p_len && i < r)
	{
		d->ans[i] = patch[p_index];
		p_index++;
		i++;
	}
	debug_print(d, first, mid, last);
	return (0);
}

int		mem_ms_merge(t_sort *d, int i, int mid, int last)
{
	int j;

	mid++;
	while (i <= last && mid <= last && i <= mid)
	{
		if (d->f(d, &(d->ans[i]), &(d->ans[mid])) == d->ans[i])
			i++;
		else
		{
			swap_ints(&(d->ans[i]), &(d->ans[mid]));
			j = mid;
			mid++;
			i++;
			while (j > i)
			{
				swap_ints(&(d->ans[j - 1]), &(d->ans[j]));
				j--;
			}
		}
	}
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
		mem_ms_merge(d, first, mid, last);
	return (0);
}

int		ms_unlock(t_sort *d, int *key, void *to_sort)
{
	int *array;
	int val_store;
	int i;
	int k;

	array = *((int **)(d->to_sort));
	i = 0;
	while (i == key[i])
		i++;
	k = i;
	val_store = array[k];
	while (key[i] != k)
	{
		array[i] = array[key[i]];
		i = key[i];
	}
	array[i] = val_store;
	
	i = 0;
	printf("Array: \n");
	while (i < d->items)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
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
	ms_unlock(&data, data.ans, to_sort);
	i = 0;
	printf("Key: \n");
	while (i < len)
	{
		printf("%d ", data.ans[i]);
		i++;
	}
	printf("\n");

	return (to_sort);
}
