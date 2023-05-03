/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 19:38:47 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 20:50:44 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link *do_radix(t_data *d, t_link *solution)
{
	int	bits_to_shift;
	int i;
	int j;

	bits_to_shift = 0;
	while (((d->num_of_args - 1) >> bits_to_shift) != 0)
		bits_to_shift++;
	i = 0;
	while (i < bits_to_shift)
	{
		j = 0;
		while (j < d->num_of_args)
		{
			if(((d->stack_a->content >> i)&1) == 1)
				solution = apply_op(d, ra, solution);
			else
				solution = apply_op(d, pb, solution);
			j++;
		}
		i++;
		while (size_of_list(d->stack_b) != 0)
			solution = apply_op(d, pa, solution);
	}
	return (solution);
}

t_link	*radix_sort(t_data *d)
{
	t_link	*solution;

	solution = NULL;
	set_or_reset_stacks(d);
	while (stacks_sorted(d) != 2)
	{
		solution = do_radix(d, solution);
	}
	return (solution);
}