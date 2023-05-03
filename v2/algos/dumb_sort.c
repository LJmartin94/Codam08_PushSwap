/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dumb_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 16:23:53 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 19:42:56 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*target_pb(t_data *d, t_link *solution)
{
	t_link	*tmp;
	int		target;
	int		pos;

	target = d->num_of_args - size_of_list(d->stack_a);
	tmp = d->stack_a;
	pos = 0;
	while (tmp && tmp->content != target)
	{
		tmp = tmp->below;
		pos++;
	}
	if (d->stack_a && d->stack_a->content != target)
	{
		if (pos <= (size_of_list(d->stack_a) / 2))
			return (apply_op(d, &ra, solution));
		else
			return (apply_op(d, &rra, solution));
	}
	else
		return (apply_op(d, &pb, solution));
}

t_link	*dumb_sort(t_data *d)
{
	t_link	*solution;

	solution = NULL;
	set_or_reset_stacks(d);
	while (stacks_sorted(d) != 2)
	{
		if (stacks_sorted(d) == 0)
		{
			solution = target_pb(d, solution);
		}
		else
			solution = apply_op(d, &pa, solution);
	}
	return (solution);
}
