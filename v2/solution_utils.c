/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solution_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 14:45:11 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 23:42:48 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link *delete_two_nodes(t_link *head, t_link *first)
{
	t_link	*second;
	t_link	*third;

	second = first->below;
	third = second->below;
	third->above = first->above;
	if (first->above == NULL)
	{
		free(first);
		free(second);
		return(third);
	}
	third->above->below = third;
	return (head);
}

void	optimise_solution(t_link **solution)
{
	t_link	*head;
	t_link	*to_check;

	head = *solution;
	to_check = head;
	while(to_check->below)
	{
		if((to_check->content == PB && to_check->below->content == PA) || \
			(to_check->content == PA && to_check->below->content == PB) || \
			(to_check->content == SA && to_check->below->content == SA) || \
			(to_check->content == SB && to_check->below->content == SB) || \
			(to_check->content == SS && to_check->below->content == SS) || \
			(to_check->content == RA && to_check->below->content == RRA) || \
			(to_check->content == RB && to_check->below->content == RRB) || \
			(to_check->content == RR && to_check->below->content == RRR) || \
			(to_check->content == RRA && to_check->below->content == RA) || \
			(to_check->content == RRB && to_check->below->content == RB) || \
			(to_check->content == RRR && to_check->below->content == RR))
			{
				head = delete_two_nodes(head, to_check);
				to_check = head;
			}
		else
			to_check = to_check->below;
	}
	*solution = head;
}

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

void	write_rotate(t_link *solution)
{
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
}

void	write_solution(t_link *solution)
{
	while (solution)
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
		if (solution-> content == RA || solution-> content == RB || \
			solution->content == RR || solution->content == RRR || \
			solution->content == RRA || solution->content == RRB)
			write_rotate(solution);
		solution = solution->below;
	}
}
