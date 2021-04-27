/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_error_management.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:44:47 by limartin      #+#    #+#                 */
/*   Updated: 2021/04/27 19:12:49 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Throws errors if:
** Args are not integers
** Args are larger than int MAX or less than int MIN
** -0 or +Num aren't valid number formats
** Duplicate args?!
** Bad instruction
** Allow for options -v and -v2
*/

int error(void)
{
	write(1, "Error, init?\n", 13);
	exit(1);
	return (1);
}

int	sanitise_input_string(char **argv, int *argc, t_stack *stk)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < (*argc))
	{
		if (ft_is_numeric(argv[i]))
		{
			argv[j] = argv[i];
			j++;
		}	
		else if (are_strs_eq("-v", argv[i]))
			stk->vis = 1;
		else if (are_strs_eq("-v2", argv[i]))
			stk->vis = 2;
		else
			return (error());
		i++;
	}
	(*argc) = j;
	return (j);
}

int	argument_error_checker(char **argv, int *argc, t_stack *stk)
{
	sanitise_input_string(argv, argc, stk);
	return (0);
}