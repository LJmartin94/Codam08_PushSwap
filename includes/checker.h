/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:15:12 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 16:46:37 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "general.h"

# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"

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

int				init_stack(int argc, char **argv, t_stack *stack);
int				recalculate_head(t_stack *stack, int head);

int				a(int index, t_stack *stack);
int				b(int index, t_stack *stack);
int				valid_a(int i, t_stack *stk);
int				valid_b(int i, t_stack *stk);

int				pa(t_stack *stk);
int				pb(t_stack *stk);
int				sa(t_stack *stk);
int				sb(t_stack *stk);
int				ss(t_stack *stk);
int				ra(t_stack *stk);
int				rb(t_stack *stk);
int				rr(t_stack *stk);
int				rra(t_stack *stk);
int				rrb(t_stack *stk);
int				rrr(t_stack *stk);

int				visualise_stacks(t_stack *stk);

#endif
