/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils_merge_sort.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 18:54:23 by limartin      #+#    #+#                 */
/*   Updated: 2021/04/29 21:55:06 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

#include <stdio.h>

void 	*merge_sort(void *to_sort, int mem, int (*f)(void *, void *))
{
	//void *swap;
	int data_type;

	data_type = sizeof(to_sort)[0];
	printf("Size: %d\n", data_type);
	printf("Data: %d\n", ((int *)to_sort)[0]);

	f(((unsigned char)to_sort + 0 * mem), ((unsigned char)to_sort + 1 * mem));
	return (to_sort);
}