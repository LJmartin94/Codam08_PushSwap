/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:40:57 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/30 01:02:42 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //exit
# include <unistd.h> //write
# include <limits.h> //INT_MAX && INT_MIN

// The type of struct we use to represent our stack_a and stack_b
// AND
// The type of struct we use to store our instruction list in
typedef struct s_link
{
	int				content;
	struct s_link	*above; //above
	struct s_link	*below; //below
}	t_link;

//data struct -> anything that is malloc'd and needs to be freed goes in here.
typedef struct s_data
{
	int		*input;
	int		num_of_args;
	t_link	*stack_a;
	t_link	*stack_b;
	t_link	*solution_a;
}	t_data;

//utils.c
int		ft_strlen(const char *str);
int		ft_modified_atoi(t_data *d, char *str);

//parsing.c
void	parsing(t_data *d, int argc, char **argv);

//linked_lists.c
int		size_of_list(t_link *to_count);
t_link	*new_node(t_data *d, int content);
t_link	*add_to_back(t_link *head, t_link *to_add);
t_link	*copy_list(t_data *d, t_link *to_copy);

//ops
void 	op_px(t_link **to_stack, t_link **from_stack);
void	pa(t_data *d);
void	pb(t_data *d);

void 	op_sx(t_link **stack);
void	sa(t_data *d);
void	sb(t_data *d);
void	ss(t_data *d);

void 	op_rx(t_link **stack);
void	ra(t_data *d);
void	rb(t_data *d);
void	rr(t_data *d);

void 	op_rrx(t_link **stack);
void	rra(t_data *d);
void	rrb(t_data *d);
void	rrr(t_data *d);


//exit.c
void	exit_with_message(t_data *d, char *msg, int error);

//debug.c -> functions and includes to be removed before handing in.
# include <stdio.h>

void	print_list(t_link *to_print);

#endif