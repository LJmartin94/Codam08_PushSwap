/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:27:51 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/22 21:09:08 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

typedef int	(*t_instruction)(t_stack *);

int	specific_function(t_stack *stk)
{
	(void)stk;
	printf("This shit actually works?!\n");
	return (0);
}

t_instruction	get_instruction(char *line)
{
	(void)line;
	return (specific_function);
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
	}
	return (0);
}
