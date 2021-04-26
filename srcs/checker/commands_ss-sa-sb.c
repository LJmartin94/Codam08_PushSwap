/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_ss-sa-sb.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:28:15 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 15:02:22 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sa(t_stack *stk)
{
	if (valid_a(0, stk) && valid_a(1, stk))
	{
		stk->swap = stk->stack[a(0, stk)];
		stk->stack[a(0, stk)] = stk->stack[a(1, stk)];
		stk->stack[a(1, stk)] = stk->swap;
	}
	return (0);
}

int	sb(t_stack *stk)
{
	if (valid_b(0, stk) && valid_b(1, stk))
	{
		stk->swap = stk->stack[b(0, stk)];
		stk->stack[b(0, stk)] = stk->stack[b(1, stk)];
		stk->stack[b(1, stk)] = stk->swap;
	}
	return (0);
}

int	ss(t_stack *stk)
{
	sa(stk);
	sb(stk);
	return (0);
}
