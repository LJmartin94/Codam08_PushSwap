/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_stack_manager_indices.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:58:38 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 16:51:53 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	a(int index, t_stack *stack)
{
	index = index + stack->head;
	return (index);
}

int	b(int index, t_stack *stack)
{
	index = stack->head - 1 - index;
	return (index);
}

int	valid_a(int i, t_stack *stk)
{
	if (a(i, stk) >= stk->head && a(i, stk) < (stk->head + stk->a_len))
		return (1);
	else
		return (0);
}

int	valid_b(int i, t_stack *stk)
{
	if (b(i, stk) < stk->head && b(i, stk) >= 0)
		return (1);
	else
		return (0);
}
