/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   px.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 01:40:28 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/29 21:45:27 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes TO stack X (from the other stack) */
void op_px(t_link **to, t_link **from)
{
	t_link *to_move;

	if (*from == NULL)
		return;
	to_move = *from; //top of 'from' stack
	to_move->below->above = NULL;
	to_move->below = *to; 
	to = to_move;




	if (to_move->above != NULL)
		to_move->above->below = NULL;
	else
		*from = NULL;
	dest = *to;
	if (dest == NULL)
		*to = to_move;
	else
	{
		while (dest->below)
			dest = dest->below;
		dest->below = to_move;
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
