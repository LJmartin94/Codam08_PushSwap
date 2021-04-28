/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils_atoi.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 20:28:30 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/28 16:20:28 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void *free_and_null(int *stack_a)
{
	free(stack_a);
	return (NULL);
}

int check_for_overflow(int num, char *str)
{
	if (num > 0 || num < -1)
		return (0);
	else if (num == 0 && !(are_strs_eq("0", str)))
		return (1);
	else if (num == -1 && !(are_strs_eq("-1", str)))
		return (1);
	else
		return(0);
}

int	mod_ft_atoi(const char *str)
{
	int			i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (are_strs_eq(str, "-2147483648"))
		return (-2147483648);
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	if ((i > 0) && (str[i - 1] == '-'))
		sign = -1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (((str[i] - '0') + (res * 10)) < res)
			return (((-1 * sign) - 1) / 2);
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return ((int)(res * sign));
}

int	ft_is_numeric(const char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret = 1;
		else
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}

int	*str_to_int_arrays(char **strs, int len)
{
	int	*stack_a;
	int	arg;

	stack_a = (int *)malloc(sizeof(int) * len);
	if (stack_a == NULL)
		return (NULL);
	arg = 0;
	while (arg < len)
	{
		if (ft_is_numeric(strs[arg]))
			stack_a[arg] = mod_ft_atoi(strs[arg]);
		else 
			return (free_and_null(stack_a));
		if (check_for_overflow(stack_a[arg], strs[arg]))
			return (free_and_null(stack_a));
		arg++;
	}
	return (stack_a);
}
