/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_error_management.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:44:47 by limartin      #+#    #+#                 */
/*   Updated: 2021/05/02 16:36:59 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Throws errors if:
** Args are not integers
** No args (or only options)
** Allow for options -v and -v2
** Args are larger than int MAX or less than int MIN
** -0 or +Num aren't valid number formats
**
** Duplicate args?!
** Bad instruction
*/

int error(void)
{
	int ret;

	ret = write(1, "Error, init?\n", 13);
	exit(1);
	return (ret);
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
	if ((*argc) == 0)
		return (error());
	return (0);
}