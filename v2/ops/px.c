/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   px.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 01:40:28 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/28 17:45:50 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes TO stack X (from the other stack) */
void op_px(t_link **to, t_link **from)
{
	t_link *to_move;
	t_link *dest;

	if (*from == NULL)
		return;
	to_move = *from;
	while (to_move->next)
		to_move = to_move->next;
	if (to_move->previous != NULL)
		to_move->previous->next = NULL;
	else
		*from = NULL;
	dest = *to;
	if (dest == NULL)
		*to = to_move;
	else
	{
		while (dest->next)
			dest = dest->next;
		dest->next = to_move;
	}	
	return;
}

void pa(t_data *d)
{
	op_px(&d->stack_a, &d->stack_b);
	return;
}

void pb(t_data *d)
{
	op_px(&d->stack_b, &d->stack_a);
	return;
}
