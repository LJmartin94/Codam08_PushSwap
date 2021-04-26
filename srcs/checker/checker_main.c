/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:27:51 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 19:39:16 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	specific_function(t_stack *stk)
{
	(void)stk;
	printf("This shit actually works?!\n");
	return (0);
}

int	error_function(t_stack *stk)
{
	(void)stk;
	printf("Command not recognised\n");
	return (0);
}

t_instruction	get_instruction(char *line)
{
	static t_switch_obj const	s[] = {
		{(char *) "pa", pa}, {(char *) "pb", pb},
		{(char *) "ra", ra}, {(char *) "rb", rb}, {(char *) "rr", rr},
		{(char *) "sa", sa}, {(char *) "sb", sb}, {(char *) "ss", ss},
		{(char *) "rra", rra}, {(char *) "rrb", rrb}, {(char *) "rrr", rrr}
	};
	t_instruction				result;
	int							i;

	result = error_function;
	i = 0;
	while (i < (int)(sizeof(s) / sizeof(t_switch_obj)))
	{
		if (are_strs_eq(line, s[i].condition))
			return ((s[i]).res);
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int				run;
	t_stack			stk;
	char			*line;
	t_instruction	instruction;

	init_stack(argc, argv, &stk);
	run = 1;
	while (run)
	{
		run = get_next_line(1, &line);
		if (line[0] == '\0')
			break ;
		instruction = get_instruction(line);
		instruction(&stk);
		visualise_stacks2(&stk);
		free (line);
	}
	validate_stacks(&stk);
	return (0);
}

/*
** TO DO:
** Error management
** Protect malloc fails
** Free everything malloc'd
** Make visualiser and visualiser2 work with -v and -v2
*/
