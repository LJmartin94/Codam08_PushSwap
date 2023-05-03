/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 21:38:00 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 23:52:57 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_link *list)
{
	t_link	*below_node;

	while (list != NULL)
	{
		below_node = list->below;
		list->below = NULL;
		list->above = NULL;
		free(list);
		list = below_node;
	}
	return ;
}

void	free_all(t_data *d)
{
	free(d->input);
	d->input = NULL;
	free(d->sorted_input);
	d->sorted_input = NULL;
	free_list(d->stack_a);
	free_list(d->stack_b);
	// free_list(d->solutions); //no longer works this way
}

/* I like separating the output from the input with a newline, 
but I'm sure the checker will hate it*/
void	exit_with_message(t_data *d, char *msg, int error)
{
	free_all(d);
	write(1, "\n", 1);
	(void)msg;
	if (error)
		write(1, "Error\n", ft_strlen("Error\n"));
	exit(error);
}
