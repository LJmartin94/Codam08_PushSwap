/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 21:38:00 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/29 18:15:40 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_link *list)
{
	t_link *next_node;
	
	while(list != NULL)
	{
		next_node = list->next;
		list->next = NULL;
		list->previous = NULL;
		free(list);
		list = next_node;
	}
	return;
}

void	free_all(t_data *d)
{
	if (d->input != NULL)
		free(d->input);
	d->input = NULL;
	free_list(d->stack_a);
	free_list(d->stack_b);
	free_list(d->solution_a);
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
