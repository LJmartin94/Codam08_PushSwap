/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:41:04 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/22 00:53:25 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	initialise_data(t_data *d)
{
	d->input = NULL;
	d->num_of_args = 0;
	d->stack_a = NULL;
	d->stack_b = NULL;
	d->solution_a = NULL;
	return ;
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		i;

	initialise_data(&d);
	parsing(&d, argc, argv);
	i = 0;
	while (i < d.num_of_args)
	{
		d.stack_a = add_to_back(d.stack_a, new_node(&d, d.input[i]));
		i++;
	}
	printf("List length: %d\n", size_of_list(d.stack_a));
	return (0);
}
