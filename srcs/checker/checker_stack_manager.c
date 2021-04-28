/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_stack_manager.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:58:38 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/28 14:43:19 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	recalculate_head(t_stack *stack, int head)
{
	stack->head = head;
	stack->a_len = stack->total_len - stack->head;
	stack->b_len = stack->total_len - stack->a_len;
	return (0);
}

int	init_stack(int argc, char **argv, t_stack *stack)
{
	stack->total_len = argc;
	stack->stack = str_to_int_arrays(argv, stack->total_len);
	recalculate_head(stack, 0);
	return (0);
}
