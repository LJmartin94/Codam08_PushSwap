/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rx.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 01:40:17 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 16:24:03 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves 'to_move' from its starting position above 'new_head' to its final position below 'old_tail'
int op_rx(t_link **stack)
{
	t_link *to_move; //the node that moves from the top of the stack to the bottom
	t_link *new_head; //the node that is underneath the moving node, which becomes the new top of the stack
	t_link *old_tail; //the node that is at the bottom of the stack, until the moving node moves below it

	if (size_of_list(*stack) < 3) //if there are fewer than 3 nodes on a stack, a rotate behaves like a swap
		return(op_sx(stack));
	to_move = *stack; //the node to move is the one at the top of the stack
	new_head = to_move->below; //the new head is the one below to_move, which becomes the top when it moves down.
	old_tail = new_head; //lets assume that 'new_head' is the lowest node.
	while (old_tail->below) //whilst there is a node below what we thought was the lowest node, make that the lowest node instead.
		old_tail = old_tail->below;
	
	//From lowest to highest in the stack:
	to_move->below = NULL; //to_move should be lowest, so have nothing underneath.
	to_move->above = old_tail; //to_move's upstairs neighbour should be the node that was previously lowest.
	old_tail->below = to_move; //old_tail's downstairs neighbour is now the node that moved, but their upstairs neighbour stays the same
	new_head->above = NULL; //In fact, everyone's upstairs neighbour stays the same, except new_head. It no longer points to the node that moved, but instead points to nothing.
	*stack = new_head; //Finally, we need to make sure our data struct knows that this stack now starts with the node that was exposed when to_move got taken off.
	return(1);
}

enum e_operation ra(t_data *d)
{
	return (op_rx(&d->stack_a) * RA);
}

enum e_operation rb(t_data *d)
{
	return (op_rx(&d->stack_b) * RB);
}

enum e_operation rr(t_data *d)
{
	int res;
	
	res = ra(d) + rb(d);
	if (res == RA + RB)
		return(RR);
	else
		return(res);
}