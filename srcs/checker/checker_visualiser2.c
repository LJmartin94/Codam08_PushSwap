/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_visualiser2.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 12:57:44 by limartin      #+#    #+#                 */
/*   Updated: 2021/04/26 19:36:38 by limartin      ########   odam.nl         */
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
	write(1, " ", 1);
	return (len);
}

int	visualise_stacks2(t_stack *stk)
{
	char	**str_ary;
	int		i;

	str_ary = int_array_to_strs(stk->stack, stk->total_len);
	i = 0;
	while (i < stk->total_len)
	{
		if (i == stk->head)
			write(1, " <B|A> ", 7);
		set_colour((i < stk->total_len - 1), (i + 1), i, stk);
		write_num((1), i, str_ary);
		write (1, NRM, ft_strlen(NRM));
		i++;
	}
	write (1, NRM, ft_strlen(NRM));
	write(1, "\n", 1);
	return (0);
}
