/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:41:04 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/28 17:46:21 by limartin      ########   odam.nl         */
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
	pb(&d);
	pb(&d);
	pb(&d);
	pb(&d);
	printf("Stack a: ");
	print_list(d.stack_a);
	printf("Stack b: ");
	print_list(d.stack_b);
	printf("Stack_a len: %d, Stack_b len: %d\n", size_of_list(d.stack_a), size_of_list(d.stack_b));
	return (0);
}
