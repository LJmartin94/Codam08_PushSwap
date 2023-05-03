/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_solutions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 16:12:07 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 20:47:32 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_or_reset_stacks(t_data *d)
{
	int i;

	if (d->stack_a != NULL)
	{
		free_list(d->stack_a);
		d->stack_a = NULL;
	}
	if (d->stack_b != NULL)
	{
		free_list(d->stack_b);
		d->stack_b = NULL;
	}
	i = 0;
	while (i < d->num_of_args)
	{
		d->stack_a = add_to_back(d->stack_a, new_node(d, d->input[i]));
		i++;
	}
}

void	try_solutions(t_data *d)
{
	int shortest;
	int index;

	d->solutions = (t_link **)malloc(sizeof(t_link *) * SOLUTIONS_TOTAL);
	d->solutions[DUMB_SORT] = dumb_sort(d);
	printf("Dumb sort ops: %d\n", size_of_list(d->solutions[DUMB_SORT]));
	d->solutions[RADIX_SORT] = radix_sort(d);
	printf("Radix sort ops: %d\n", size_of_list(d->solutions[RADIX_SORT]));
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
