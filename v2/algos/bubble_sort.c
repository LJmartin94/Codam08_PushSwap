/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 17:06:00 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/04 17:55:18 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*do_bubble(t_data *d, t_link *solution)
{
	while (size_of_list(d->stack_a) >= 2)
	{
		if (d->stack_a->content < d->stack_a->below->content)
			solution = apply_op(d, pb, solution);
		else
			solution = apply_op(d, sa, solution);
	}
	while (size_of_list(d->stack_b) >= 2)
	{
		if (d->stack_b->content > d->stack_b->below->content)
			solution = apply_op(d, pa, solution);
		else
			solution = apply_op(d, sb, solution);
	}
	while (size_of_list(d->stack_b) != 0)
		solution = apply_op(d, pa, solution);
	return (solution);
}

t_link	*bubble_sort(t_data *d)
{
	t_link	*solution;

	solution = NULL;
	set_or_reset_stacks(d);
	while (stacks_sorted(d) != 2)
	{
		solution = do_bubble(d, solution);
	}
	return (solution);
}
