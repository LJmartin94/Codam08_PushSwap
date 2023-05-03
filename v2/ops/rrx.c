/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 01:40:13 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 16:09:17 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves 'to_move' from its starting position below 'new_tail' to its final position above 'old_head'
int op_rrx(t_link **stack)
{
	t_link *old_head; //the node that is at the top of the stack, until the moving node moves above it
	t_link *new_tail; //the node that is above the moving node, which becomes the new bottom of the stack
	t_link *to_move; //the node that moves from the bottom of the stack to the top

	if (size_of_list(*stack) < 3) //if there are fewer than 3 nodes on a stack, a reverse rotate behaves like a swap
		return(op_sx(stack));
	old_head = *stack; //the 'old_head' starts at the top of the stack when the function is first called.
	to_move = old_head->below; //We need to move the lowest node: the node to move is somewhere below the old_head
	while(to_move->below) //whilst there is a node below what we thought was the lowest node, make that the lowest node instead.
		to_move = to_move->below;
	new_tail = to_move->above; //the new_tail will be the upstairs neighbour directly above the lowest node, before we move it.
	
	//From lowest to highest in the stack:
	new_tail->below = NULL; //the node that previously had our moving node as a downstairs neighbour, now has nothing below it.
	old_head->above = to_move; //the node that previously was on top now has our moving node as an upstairs neighbour.
	to_move->below = old_head; //the node we moved now has what used to be the top of the stack as a downstairs neighbour.
	to_move->above = NULL; //the node we moved now has nothing left above it.
	*stack = to_move; //Finally, we need to make sure our data struct knows that this stack now starts with the node that we moved from bottom to top
	return (1);
}

enum e_operation	rra(t_data *d)
{
	return (op_rrx(&d->stack_a) * RRA);
}

enum e_operation	rrb(t_data *d)
{
	return (op_rrx(&d->stack_b) * RRB);
}

enum e_operation	rrr(t_data *d)
{
	int res;
	
	res = rra(d) + rrb(d);
	if (res == RRA + RRB)
		return(RRR);
	else
		return(res);
}