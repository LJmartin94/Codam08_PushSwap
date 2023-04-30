/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:41:04 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/30 16:14:49 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	initialise_data(t_data *d)
{
	d->input = NULL;
	d->sorted_input = NULL;
	d->num_of_args = 0;
	d->stack_a = NULL;
	d->stack_b = NULL;
	d->solutions = NULL;
	return ;
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		i;

	initialise_data(&d);
	parsing(&d, argc, argv);
	translate_input(&d);
	i = 0;
	while (i < d.num_of_args)
	{
		d.stack_a = add_to_back(d.stack_a, new_node(&d, d.input[i]));
		i++;
	}
	printf("Start Stack a: ");
	print_list(d.stack_a);
	printf("Start Stack b: ");
	print_list(d.stack_b);
	try_solutions(&d);
	printf("End Stack a: ");
	print_list(d.stack_a);
	printf("End Stack b: ");
	print_list(d.stack_b);
	printf("Stack_a len: %d, Stack_b len: %d\n", \
	size_of_list(d.stack_a), size_of_list(d.stack_b));
	return (0);
}
