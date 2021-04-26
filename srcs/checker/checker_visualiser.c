/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_visualiser.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 12:57:44 by limartin      #+#    #+#                 */
/*   Updated: 2021/04/26 13:28:20 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	visualise_stacks(t_stack *stk)
{
	char	**str_ary;
	int		i;

	str_ary = int_array_to_strs(stk->stack, stk->total_len);
	write(1, "A | B\n", 6);
	i = 0;
	while (i < stk->total_len)
	{
		write(1, "X | X\n", 6);
		i++;
	}
	return (0);
}