/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:27:51 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 15:04:55 by limartin      ########   odam.nl         */
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
		{(char *) "ra", specific_function}, {(char *) "rb", specific_function},
		{(char *) "rr", specific_function}, {(char *) "ss", ss},
		{(char *) "sa", sa}, {(char *) "sb", sb},
		{(char *) "rra", specific_function},
		{(char *) "rrb", specific_function},
		{(char *) "rrr", specific_function}
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
		visualise_stacks(&stk);
	}
	return (0);
}

/*
** TO DO:
** Error management
** Protect malloc fails
** Perform operations on int array
** Validate sequence is sorted
** Convert ints back to str
** Visualise strings
*/
