/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 21:38:00 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/21 21:42:01 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_data *d)
{
	if (d->input != NULL)
		free(d->input);
	d->input = NULL;
}

/* I like separating the output from the input with a newline, 
but I'm sure the checker will hate it*/
void	exit_with_message(t_data *d, char *msg, int error)
{
	free_all(d);
	write(1, "\n", 1);
	if (error)
		write(1, msg, ft_strlen(msg));
	exit(error);
}
