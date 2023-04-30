/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:40:57 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/30 16:24:30 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //exit
# include <unistd.h> //write
# include <limits.h> //INT_MAX && INT_MIN

enum Solution
{
	DUMB_SORT,
	SOLUTIONS_TOTAL,
};

enum Operation
{
	ERROR,
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
int		ft_strlen(const char *str);
int		ft_modified_atoi(t_data *d, char *str);

//parsing.c
void	parsing(t_data *d, int argc, char **argv);

//sort_input.c
void	translate_input(t_data *d);

//linked_lists.c
int		size_of_list(t_link *to_count);
t_link	*new_node(t_data *d, int content);
t_link	*add_to_back(t_link *head, t_link *to_add);
t_link	*copy_list(t_data *d, t_link *to_copy);

//try_solutions.c
void	try_solutions(t_data *d);

//algos
t_link *dumb_sort(t_data *d);

//ops
void	op_px(t_link **to_stack, t_link **from_stack);
void	pa(t_data *d);
void	pb(t_data *d);

void	op_sx(t_link **stack);
void	sa(t_data *d);
void	sb(t_data *d);
void	ss(t_data *d);

void	op_rx(t_link **stack);
void	ra(t_data *d);
void	rb(t_data *d);
void	rr(t_data *d);

void	op_rrx(t_link **stack);
void	rra(t_data *d);
void	rrb(t_data *d);
void	rrr(t_data *d);

//exit.c
void	exit_with_message(t_data *d, char *msg, int error);

//debug.c -> functions and includes to be removed before handing in.
# include <stdio.h>

void	print_list(t_link *to_print);

#endif