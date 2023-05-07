/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sim_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 16:23:53 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/05 02:06:10 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_unsorted_nodes(t_data *d)
{
	t_link	*compare;
	t_link	*last;
	int		unsorted;

	compare = d->stack_a;
	unsorted = 0;
	while (compare && compare->below)
	{
		if (compare->content > compare->below->content)
			unsorted++;
		compare = compare->below;
	}
	if (size_of_list(d->stack_a) && size_of_list(d->stack_b) && \
	 d->stack_a->content < d->stack_b->content)
		unsorted++;
	compare = d->stack_b;
	while(compare && compare->below)
	{
		if (compare->content < compare->below->content)
			unsorted++;
		compare = compare->below;
	}
	return (unsorted);
}

enum e_operation undo_op(enum e_operation to_try)
{
	if (to_try == PA)
		return (PB);
	if (to_try == PB)
		return (PA);
	if (to_try == SA)
		return (SA);
	if (to_try == SB)
		return (SB);
	if (to_try == SS)
		return (SS);
	if (to_try == RA)
		return (RRA);
	if (to_try == RB)
		return (RRB);
	if (to_try == RR)
		return (RRR);
	if (to_try == RRA)
		return (RA);
	if (to_try == RRB)
		return (RB);
	if (to_try == RRR)
		return (RR);
}

t_op_func trans_enum(enum e_operation to_try)
{
	if (to_try == PA)
		return (pa);
	if (to_try == PB)
		return (pb);
	if (to_try == SA)
		return (sa);
	if (to_try == SB)
		return (sb);
	if (to_try == SS)
		return (ss);
	if (to_try == RA)
		return (ra);
	if (to_try == RB)
		return (rb);
	if (to_try == RR)
		return (rr);
	if (to_try == RRA)
		return (rra);
	if (to_try == RRB)
		return (rrb);
	if (to_try == RRR)
		return (rrr);
}

// 0 no diff, < 0 means less sorted, > 0 means more sorted.
int		sort_diff(t_data *d, enum e_operation to_try)
{
	t_link	*sim;
	int		res;
	enum e_operation (*f)(t_data *d);

	sim = NULL;
	f = trans_enum(to_try);
	sim = apply_op(d, f, sim);
	res = count_unsorted_nodes(d);
	if (sim && sim->content)
	{
		to_try = undo_op(to_try);
		f = trans_enum(to_try);
		sim = apply_op(d, f, sim);
	}
	free(sim);
	return (res);
}

t_link *do_sim(t_data *d, t_link *solution)
{
	int					op_results[OPS_TOTAL];
	enum e_operation	op;
	t_link				*sim;
	int					sim_result;
	enum e_operation	best_op;

	op_results[ERROR] = 999999;
	op = PA;
	while(op < OPS_TOTAL)
	{
		op_results[op] = sort_diff(d, op);
		op++;
	}
	sim = NULL;
	if(size_of_list(d->stack_b))
	{
		sim = apply_op(d, pa, sim);
		op = SA;
		while(op < OPS_TOTAL)
		{
			sim_result = sort_diff(d, op);
			if (sim_result < op_results[PA])
				op_results[PA] = sim_result;
			op++;
		}
		sim = apply_op(d, pb, sim);
	}
	if(size_of_list(d->stack_a))
	{
		sim = apply_op(d, pb, sim);
		op = SA;
		while(op < OPS_TOTAL)
		{
			sim_result = sort_diff(d, op);
			if (sim_result < op_results[PB])
				op_results[PB] = sim_result;
			op++;
		}
		sim = apply_op(d, pa, sim);
	}
	free(sim);
	op = ERROR + 1;
	sim_result = 999999999;
	best_op = PA;
	while (op < OPS_TOTAL)
	{
		if (op_results[op] < sim_result)
		{
			best_op = op;
			sim_result = op_results[op];
		}
		op++;
	}
	printf("OP to try: %d\n", best_op);
	solution = apply_op(d, trans_enum(best_op), solution);
	return (solution);
}

t_link				*sim_sort(t_data *d)
{
	t_link *solution;
	int iters = 0;

	solution = NULL;
	set_or_reset_stacks(d);
	while (stacks_sorted(d) != 2)
	{
		solution = do_sim(d, solution);
		iters++;
		if (iters > 3)
			break;
	}
	return (solution);
}