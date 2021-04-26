/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_rrr-rra-rrb.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:28:08 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 16:49:45 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rra(t_stack *stk)
{
	int	i;
	int	last;

	if (valid_a(0, stk) && valid_a(1, stk))
	{
		last = stk->a_len - 1;
		stk->swap = stk->stack[a(last, stk)];
		i = last;
		while (i > 0)
		{
			stk->stack[a(i, stk)] = stk->stack[a((i - 1), stk)];
			i--;
		}
		stk->stack[a(0, stk)] = stk->swap;
	}
	return (0);
}

int	rrb(t_stack *stk)
{
	int	i;
	int	last;

	if (valid_b(0, stk) && valid_b(1, stk))
	{
		last = stk->b_len - 1;
		stk->swap = stk->stack[b(last, stk)];
		i = last;
		while (i > 0)
		{
			stk->stack[b(i, stk)] = stk->stack[b((i - 1), stk)];
			i--;
		}
		stk->stack[b(0, stk)] = stk->swap;
	}
	return (0);
}

int	rrr(t_stack *stk)
{
	rra(stk);
	rrb(stk);
	return (0);
}
