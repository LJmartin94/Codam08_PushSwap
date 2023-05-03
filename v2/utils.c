/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:40:52 by limartin      #+#    #+#                 */
/*   Updated: 2023/05/03 14:33:42 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*returns 0 if stacks are unsorted, 1 if both stacks are sorted but there is 
still something on stack B, and 2 if everything is fully sorted on A*/
int	stacks_sorted(t_data *d)
{
	t_link	*to_check;

	to_check = d->stack_a;
	while (to_check && to_check->below)
	{
		if (to_check->content > to_check->below->content)
			return (0);
		to_check = to_check->below;
	}
	to_check = d->stack_b;
	while (to_check && to_check->below)
	{
		if (to_check->content < to_check->below->content)
			return (0);
		to_check = to_check->below;
	}
	if (size_of_list(d->stack_b))
		return (1);
	return (2);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* This is like a standard atoi but if it encounters an integer overflow error 
it exits the program with an error message. */
int	ft_modified_atoi(t_data *d, char *str)
{
	int			i;
	long int	sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	if ((i > 0) && (str[i - 1] == '-'))
		sign = -1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = (str[i] - '0') + (res * 10);
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			exit_with_message(d, "INT overflow in input\n", 1);
		i++;
	}
	return ((int)(res * sign));
}
