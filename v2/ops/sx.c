/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sx.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 01:40:10 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/29 21:45:27 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_sx(t_link **stack)
{
	t_link *top;
	t_link *second;

	if (size_of_list(*stack) < 2)
		return;
	top = *stack;
	while (top->below != NULL)
		top = top->below;
	second = top->above;

	top->below = second;
	top->above = second->above;
	top->above->below = top;
	second->below = NULL;
	second->above = top;
	//still need to check whether there are 3 elems in the stack otherwise this wont work
}