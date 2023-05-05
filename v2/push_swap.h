/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:40:57 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/05 02:06:36 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //exit
# include <unistd.h> //write
# include <limits.h> //INT_MAX && INT_MIN

enum e_solution
{
	DUMB_SORT,
	RADIX_SORT,
	// BUBBLE_SORT,
	SIM_SORT,
	SOLUTIONS_TOTAL,
};

enum e_operation
{
	ERROR,
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OPS_TOTAL,
};


// The type of struct we use to represent our stack_a and stack_b
// AND
// The type of struct we use to store our instruction list in
typedef struct s_link
{
	int				content;
	struct s_link	*above;
	struct s_link	*below;
}	t_link;

//data struct -> anything that is malloc'd and needs to be freed goes in here.
typedef struct s_data
{
	int		*input;
	int		*sorted_input;
	int		num_of_args;
	t_link	*stack_a;
	t_link	*stack_b;
	t_link	**solutions;
}	t_data;

//utils.c
int					ft_strlen(const char *str);
int					ft_modified_atoi(t_data *d, char *str);

//solution_utils.c
int					stacks_sorted(t_data *d);
t_link				*apply_op(t_data *d, \
					enum e_operation (*op)(t_data *d), \
					t_link *solution);
void				write_solution(t_link *solution);
void				optimise_solution(t_link **solution);

//parsing.c
void				parsing(t_data *d, int argc, char **argv);

//sort_input.c
void				translate_input(t_data *d);

//linked_lists.c
int					size_of_list(t_link *to_count);
t_link				*new_node(t_data *d, int content);
t_link				*add_to_back(t_link *head, t_link *to_add);
t_link				*copy_list(t_data *d, t_link *to_copy);

//try_solutions.c
void				try_solutions(t_data *d);
void				set_or_reset_stacks(t_data *d);

//algos
t_link				*dumb_sort(t_data *d);
t_link				*radix_sort(t_data *d);
t_link				*sim_sort(t_data *d);

//ops
typedef enum e_operation (*t_op_func)(t_data *d);

int					op_px(t_link **to_stack, t_link **from_stack);
enum e_operation	pa(t_data *d);
enum e_operation	pb(t_data *d);

int					op_sx(t_link **stack);
enum e_operation	sa(t_data *d);
enum e_operation	sb(t_data *d);
enum e_operation	ss(t_data *d);

int					op_rx(t_link **stack);
enum e_operation	ra(t_data *d);
enum e_operation	rb(t_data *d);
enum e_operation	rr(t_data *d);

int					op_rrx(t_link **stack);
enum e_operation	rra(t_data *d);
enum e_operation	rrb(t_data *d);
enum e_operation	rrr(t_data *d);

//exit.c
void				free_list(t_link *list);
void				exit_with_message(t_data *d, char *msg, int error);

//debug.c -> functions and includes to be removed before handing in.
# include <stdio.h>

void				print_list(t_link *to_print);

#endif