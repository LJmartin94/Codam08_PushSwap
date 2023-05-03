/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sx.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 01:40:10 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 16:25:21 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int op_sx(t_link **stack)
{
	t_link *move_down; //starts on top, ends second
	t_link *move_up; //starts second, ends on top
	t_link *foundation; //stays in the same place (third), but gets a different 'upstairs' neighbour.

	if (size_of_list(*stack) < 2) //not enough nodes on stack to swap
		return (0);
	move_down = *stack; //the node to move down is the one that starts at the top
	move_up = (*stack)->below; //the node to move up is the one that starts underneath the top
	foundation = move_up->below; //the foundation is whatever is underneath the node that needs to be moved up

	//From lowest to highest in the stack:
	if (foundation) //foundation could be NULL/nothing if there are only two nodes on the stack, so we need to check if there is a node.
		foundation->above = move_down; //foundation should have the node that gets moved down as its upstairs neighbour
	move_down->below = foundation; //the node that gets moved down should have foundation as its downstairs neighbour
	move_down->above = move_up; //the node that gets moved down should have the node that gets moved up as its upstairs neighbour
	move_up->below = move_down; //the node that gets moved up should have the node that gets moved down as its downstairs neigbour
	move_up->above = NULL; //the node that gets moved up should have nothing at all as its upstairs neighbour
	*stack = move_up; //Finally, we need to make sure our data struct knows that this stack now starts with the node that was moved up.
	return (1);
}

enum e_operation	sa(t_data *d)
{
	return (op_sx(&d->stack_a) * SA);
}

enum e_operation	sb(t_data *d)
{
	return (op_sx(&d->stack_b) * SB);
}

enum e_operation	ss(t_data *d)
{
	int res;
	
	res = sa(d) + sb(d);
	if (res == SA + SB)
		return(SS);
	else
		return(res);
}