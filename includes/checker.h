/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:15:12 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 14:36:52 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "general.h"

typedef struct s_stack
{
	int	*stack;
	int	swap;
	int	total_len;
	int	head;
	int	a_len;
	int	b_len;
}	t_stack;

typedef int (*t_instruction)(t_stack *);

t_instruction	get_instruction(char *line);

int	init_stack(int argc, char **argv, t_stack *stack);
int	recalculate_head(t_stack *stack, int head);

int	a(int index, t_stack *stack);
int	b(int index, t_stack *stack);
int	valid_a(int i, t_stack *stk);
int	valid_b(int i, t_stack *stk);

int	pa(t_stack *stk);
int	pb(t_stack *stk);

int	visualise_stacks(t_stack *stk);

#endif
