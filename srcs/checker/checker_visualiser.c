/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_visualiser.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 12:57:44 by limartin      #+#    #+#                 */
/*   Updated: 2021/04/26 16:38:15 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	visualise_stacks(t_stack *stk)
{
	char	**str_ary;
	int		i;

	str_ary = int_array_to_strs(stk->stack, stk->total_len);
	write(1, "A          <-|->           B\n", 29);
	i = 0;
	while (i < stk->total_len)
	{
		if (valid_a(i, stk))
		{
			if (valid_a(i + 1, stk) && stk->stack[a(i + 1, stk)] < stk->stack[a(i, stk)])
				write (1, RED, ft_strlen(RED));
			else
				write (1, GRN, ft_strlen(GRN));
			write(1, str_ary[a(i, stk)], ft_strlen(str_ary[a(i, stk)]));
			write(1, "            ", 12 - ft_strlen(str_ary[a(i, stk)]));
		}
		else
			write(1, "            ", 12);
		write (1, NRM, ft_strlen(NRM));
		write(1, " | ", 3);
		if (valid_b(i, stk))
		{
			if (valid_b(i + 1, stk) && stk->stack[b(i + 1, stk)] > stk->stack[b(i, stk)])
				write (1, RED, ft_strlen(RED));
			else
				write (1, GRN, ft_strlen(GRN));
			write(1, str_ary[b(i, stk)], ft_strlen(str_ary[b(i, stk)]));
			write(1, "            ", 12 - ft_strlen(str_ary[b(i, stk)]));
		}
		write (1, NRM, ft_strlen(NRM));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
