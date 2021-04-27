/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_visualiser.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 12:57:44 by limartin      #+#    #+#                 */
/*   Updated: 2021/04/27 19:00:35 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	set_colour(int range_check, int i_grt, int i_les, t_stack *stk)
{
	if (range_check && stk->stack[i_grt] < stk->stack[i_les])
		write (1, RED, ft_strlen(RED));
	else
		write (1, GRN, ft_strlen(GRN));
	return (0);
}

static int	write_num(int range_check, int index, char **strs)
{
	int		len;
	char	*num;

	len = 0;
	if (range_check)
	{
		num = strs[index];
		len = ft_strlen(num);
		write(1, num, len);
	}
	write(1, "            ", 12 - len);
	return (len);
}

int	visualise_stacks(t_stack *stk)
{
	char	**str_ary;
	int		i;

	str_ary = int_array_to_strs(stk->stack, stk->total_len);
	write(1, "A          <-|->           B\n", 29);
	i = 0;
	while (i < stk->total_len)
	{
		set_colour(valid_a(i + 1, stk), a(i + 1, stk), a(i, stk), stk);
		write_num(valid_a(i, stk), a(i, stk), str_ary);
		write (1, NRM, ft_strlen(NRM));
		write(1, " | ", 3);
		set_colour(valid_b(i + 1, stk), b(i, stk), b(i + 1, stk), stk);
		write_num(valid_b(i, stk), b(i, stk), str_ary);
		write (1, NRM, ft_strlen(NRM));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	visualise_stack_if_requested(t_stack *stk)
{
	if (stk->vis == 1)
		return (visualise_stacks(stk));
	else if (stk->vis == 2)
		return (visualise_stacks2(stk));
	return (0);
}