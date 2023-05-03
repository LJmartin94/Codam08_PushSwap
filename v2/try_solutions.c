/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_solutions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 16:12:07 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 16:43:10 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	try_solutions(t_data *d)
{
	int shortest;
	int index;

	d->solutions = (t_link **)malloc(sizeof(t_link *) * SOLUTIONS_TOTAL);
	d->solutions[DUMB_SORT] = dumb_sort(d);
	index = 0;
	shortest = 0;
	while (index < SOLUTIONS_TOTAL)
	{
		if (size_of_list(d->solutions[index]) < \
			size_of_list(d->solutions[shortest]))
			shortest = index;
		index++;
	}
	write_solution(d->solutions[shortest]);
}
