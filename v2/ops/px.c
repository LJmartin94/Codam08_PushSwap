/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   px.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 01:40:28 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/29 23:51:39 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes TO stack X (from the other stack) */
void op_px(t_link **to_stack, t_link **from_stack)
{
	t_link *to_move;

	to_move = *from_stack; //the node to_move is the current top of 'from' stack
	if (to_move == NULL) //there is nothing to move
		return;
	*from_stack = to_move->below; //the new top of the 'from' stack should now be the node below the one we're moving.
	if (*from_stack)
		(*from_stack)->above = NULL; //the new top of the 'from' stack should now have nothing above it.
	if (*to_stack)
		(*to_stack)->above = to_move; //the old top of the 'to' stack should now have the node we're moving above it.
	to_move->below = *to_stack; //the element we're moving should have the old top of the 'to' stack below it.
	*to_stack = to_move; //the new top of the 'to' stack should now be the one we're moving.
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
