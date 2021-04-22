/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:15:12 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/22 21:10:20 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "general.h"

typedef struct	s_stack
{
	int *stack;
	int	total_len;
	int	head;
	int a_len;
	int	b_len;
} t_stack;

int	init_stack(int argc, char **argv, t_stack *stack);
int	recalculate_head(t_stack *stack, int head);
int a(int index, t_stack *stack);
int b(int index, t_stack *stack);


#endif
