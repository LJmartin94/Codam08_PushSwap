/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_pa-pb.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:27:58 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 16:51:20 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	pa(t_stack *stk)
{
	int	head;

	head = stk->head - 1;
	if (head >= 0)
		recalculate_head(stk, head);
	return (0);
}

int	pb(t_stack *stk)
{
	int	head;

	head = stk->head + 1;
	if (head <= stk->total_len)
		recalculate_head(stk, head);
	return (0);
}
