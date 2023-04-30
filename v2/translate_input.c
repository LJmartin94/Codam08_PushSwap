/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_input.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 15:15:11 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/30 15:48:37 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_input(t_data *d)
{
	int	i;
	int	swap;

	i = 0;
	while (i + 1 < d->num_of_args)
	{
		if (d->sorted_input[i] > d->sorted_input[i + 1])
		{
			swap = d->sorted_input[i];
			d->sorted_input[i] = d->sorted_input[i + 1];
			d->sorted_input[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

void	copy_input(t_data *d)
{
	int	i;

	d->sorted_input = (int *)malloc(sizeof(int) * d->num_of_args);
	i = 0;
	while (i < d->num_of_args)
	{
		d->sorted_input[i] = d->input[i];
		i++;
	}
}

/* Translate the input ints internal representation to a list of indexes, 
where the lowest number in the input will become 0, 
the second lowest will be 1, etc */
void	translate_input(t_data *d)
{
	int	i;
	int	j;

	copy_input(d);
	sort_input(d);
	i = 0;
	while (i < d->num_of_args)
	{
		j = 0;
		while (d->sorted_input[j] != d->input[i])
			j++;
		d->input[i] = j;
		i++;
	}
}
