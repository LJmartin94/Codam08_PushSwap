/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:40:57 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/21 21:36:15 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //exit
# include <unistd.h> //write
# include <limits.h> //INT_MAX && INT_MIN

//data struct -> anything that is malloc'd and needs to be freed goes in here.
typedef struct s_data
{
	int	*input;
	int	num_of_args;
}	t_data;

//utils.c
int		ft_strlen(const char *str);
void	exit_with_message(char *msg, int error);
int		ft_modified_atoi(char *str);

//parsing.c
void	parsing(t_data *d, int argc, char **argv);

#endif