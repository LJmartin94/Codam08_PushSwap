/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_rr-ra-rb.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:28:03 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 15:27:45 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ra(t_stack *stk)
{
	int i;

	if (valid_a(0, stk) && valid_a(1, stk))
	{
		stk->swap = stk->stack[a(0, stk)];
		i = 1;
		while (i < stk->a_len)
		{
			stk->stack[a((i - 1), stk)] = stk->stack[a(i, stk)];
			i++;
		}
		stk->stack[a(i - 1, stk)] = stk->swap;
	}
	return (0);
}

int	rb(t_stack *stk)
{
	int i;

	if (valid_b(0, stk) && valid_b(1, stk))
	{
		stk->swap = stk->stack[b(0, stk)];
		i = 1;
		while (i < stk->b_len)
		{
			stk->stack[b((i - 1), stk)] = stk->stack[b(i, stk)];
			i++;
		}
		stk->stack[b(i - 1, stk)] = stk->swap;
	}
	return (0);
}

int	rr(t_stack *stk)
{
	ra(stk);
	rb(stk);
	return (0);
}
