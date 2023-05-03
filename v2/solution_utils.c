/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solution_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 14:45:11 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 16:35:44 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*returns 0 if stacks are unsorted, 1 if both stacks are sorted but there is 
still something on stack B, and 2 if everything is fully sorted on A*/
int	stacks_sorted(t_data *d)
{
	t_link	*to_check;

	to_check = d->stack_a;
	while (to_check && to_check->below)
	{
		if (to_check->content > to_check->below->content)
			return (0);
		to_check = to_check->below;
	}
	to_check = d->stack_b;
	while (to_check && to_check->below)
	{
		if (to_check->content < to_check->below->content)
			return (0);
		to_check = to_check->below;
	}
	if (size_of_list(d->stack_b))
		return (1);
	return (2);
}

t_link	*apply_op(	t_data *d, \
					enum e_operation (*op)(t_data *d), \
					t_link *solution)
{
	int	op_code;

	op_code = (*op)(d);
	solution = add_to_back(solution, new_node(d, op_code));
	return (solution);
}

void	write_solution(t_link *solution)
{
	while(solution)
	{
		if (solution->content == PA)
			write(1, "pa\n", 3);
		if (solution->content == PB)
			write(1, "pb\n", 3);
		if (solution->content == SA)
			write(1, "sa\n", 3);
		if (solution->content == SB)
			write(1, "sb\n", 3);
		if (solution->content == SS)
			write(1, "ss\n", 3);
		if (solution->content == RA)
			write(1, "ra\n", 3);
		if (solution->content == RB)
			write(1, "rb\n", 3);
		if (solution->content == RR)
			write(1, "rr\n", 3);
		if (solution->content == RRA)
			write(1, "rra\n", 4);
		if (solution->content == RRB)
			write(1, "rrb\n", 4);
		if (solution->content == RRR)
			write(1, "rrr\n", 4);
		solution = solution->below;
	}
}