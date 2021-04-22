/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:27:51 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/22 20:27:53 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

typedef int	(*t_instruction)(int **, int*);

int	specific_function(int **stack, int *b_head)
{
	(void)stack;
	(void)b_head;
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
	int				*stack_a;
	int				b_head;
	int				run;
	char			*line;
	t_instruction	instruction;

	stack_a = str_to_int_arrays(argv, (argc - 1));
	b_head = 0;
	run = 1;
	while (run)
	{
		run = get_next_line(1, &line);
		if (line[0] == '\0')
			break ;
		instruction = get_instruction(line);
		instruction(&stack_a, &b_head);
	}
	return (0);
}
