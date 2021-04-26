/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_validator.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 17:35:40 by limartin      #+#    #+#                 */
/*   Updated: 2021/04/26 18:12:14 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	approve(void)
{
	write (1, GRN, ft_strlen(GRN));
	write (1, "OK", 2);
	write (1, NRM, ft_strlen(NRM));
	write (1, "\n", 1);
	return (1);
}

static int	reject(void)
{
	write (1, RED, ft_strlen(RED));
	write (1, "KO", 2);
	write (1, NRM, ft_strlen(NRM));
	write (1, "\n", 1);
	return (0);
}

int	validate_stacks(t_stack *stk)
{
	int i;

	i = 0;
	if (stk->b_len == 0)
	{
		while(i < stk->total_len - 1)
		{
			if (stk->stack[i] > stk->stack[i + 1])
				return (reject());
			i++;
		}
		return (approve());
	}
	return (reject());
}
