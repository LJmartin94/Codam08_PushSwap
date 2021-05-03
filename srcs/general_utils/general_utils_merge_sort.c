/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils_merge_sort.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 18:54:23 by limartin      #+#    #+#                 */
/*   Updated: 2021/05/03 20:47:48 by limartin      ########   odam.nl         */
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

int		mem2_ms_merge(t_sort *d, int first, int mid, int last)
{
	int i;
	int j;
	int l;
	int r;
	int l_head_set;

	i = first;
	l = first;
	r = mid + 1;
	l_head_set = 1;

	printf("l: %d, r: %d, i: %d\n", l, r, i);
	printf("Begin: ");
	debug_print(d, first, mid, last);
	while (i < mid + 1 && r <= last && l <= r)
	{
		if (d->f(d, &(d->ans[l]), &(d->ans[r])) == d->ans[l])
		{
			printf("l: %d, r: %d, i: %d\n", l, r, i);
			swap_ints(&(d->ans[i]), &(d->ans[l]));
			printf("Swapped L: ");
			debug_print(d, first, mid, last);
			i++;
			if (l_head_set)
				l++;
		}
		else
		{
			l_head_set = 0;
			swap_ints(&(d->ans[i]), &(d->ans[r]));
			printf("l: %d, r: %d, i: %d\n", l, r, i);
			printf("Swapped R: ");
			debug_print(d, first, mid, last);
			j = r;
			l = r;
			if (r + 1 <= last)
				r++;
			i++;
			while (j > mid + 1)
			{
				swap_ints(&(d->ans[j - 1]), &(d->ans[j]));
				printf("l: %d, r: %d, i: %d j: %d\n", l, r, i, j);
				printf("Inside loop: ");
				debug_print(d, first, mid, last);
				j--;
			}
		}
	}
	printf("Pre-flip: ");
	debug_print(d, first, mid, last);
	//unflip end:
	i = mid + 1;
	l = last;
	// printf("l: %d, r: %d, i: %d\n", l, r, i);
	while (l > i && !(l_head_set))
	{
		// printf("l: %d, r: %d, i: %d\n", l, r, i);
		// printf("Flipping loop: ");
		debug_print(d, first, mid, last);
		swap_ints(&(d->ans[i]), &(d->ans[l]));
		i++;
		l--;
	}





	printf("l: %d, r: %d, i: %d\n", l, r, i);
	printf("End: ");
	debug_print(d, first, mid, last);
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
		mem2_ms_merge(d, first, mid, last);
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

	return (to_sort);
}

	// printf("Comparing indexes: %d - %d - %d\n", first, mid, last);
	// debug_print(d, first, mid, last);


	// while (i <= last && r <= last && l <= mid)
	// {
	// 	if ((l >= rr) && (d->f(d, &(d->ans[l]), &(d->ans[r])) == l))
	// 		value to place = l;
	// 	if ((rr > l) && (d->f(d, &(d->ans[l]), &(d->ans[r])) == l))

	// // 	//printf("r = %d, mid = %d, l = %d, r_relative = %d, i = %d, last = %d\n", r, mid, l, (r - (mid + 1) - l), i, last);
	// // 	if (d->f(d, &(d->ans[l]), &(d->ans[r])) == l)
	// // 	{
	// // // 		if ((r - (mid + 1)) > l)
	// // // 			d->ans[i] = store[(r - (mid + 1) - l)];
	// // // 		else
	// // 			d->ans[i] = d->ans[l];
	// // 		l++;
	// // 		i++;
	// // 	} 
	// // 	else
	// // 	{
	// // 		// if ((r - (mid + 1)) >= l)
	// // 		// 	store[(r - (mid + 1) - l)] = (d->ans)[l];
	// // 		d->ans[i] = d->ans[r];
	// // 		r++;
	// // 		i++;
	// // 	}
	// }