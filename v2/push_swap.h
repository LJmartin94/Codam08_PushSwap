/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:40:57 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/22 01:43:52 by limartin      ########   odam.nl         */
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
	struct s_link	*next;
	struct s_link	*previous;
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

//exit.c
void	exit_with_message(t_data *d, char *msg, int error);

//debug.c -> functions and includes to be removed before handing in.
# include <stdio.h>

void	print_list(t_link *to_print);

#endif