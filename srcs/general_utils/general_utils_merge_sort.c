/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils_merge_sort.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 18:54:23 by limartin      #+#    #+#                 */
/*   Updated: 2021/05/02 18:43:33 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

#include <stdio.h>

int		ms_merge(t_sort *d, int first, int mid, int last)
{
	int store[mid + 1];
	int i;
	int l;
	int r;

	i = 0;
	l = first;
	r = mid + 1;
	if (d->f(d->to_sort, &(d->ans[l]), &(d->ans[r])) == l)
	{
		if ((r - (mid + 1)) > l)
			d->ans[i] = store[(r - (mid + 1) - l)];
		else
			d->ans[i] = d->ans[l];
		l++;
		i++;
	} 
	else
	{
		if ((r - (mid + 1)) >= l)
			store[(r - (mid + 1) - l)] = d->ans[l];
		d->ans[i] = d->ans[r];
		r++;
		i++;
	}
	return (0);
}

int		ms_split(t_sort *d, void *to_sort, int first, int last)
{
	int mid;

	if (last > first)
	{
		mid = ((last - first) / 2) + first;
		ms_split(d, to_sort, first, mid);
		ms_split(d, to_sort, mid + 1, last);
	}
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