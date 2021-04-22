#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int			i;
	long int	sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
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

int	*str_to_int_arrays(char **argv, int len)
{
	int	*stack_a;
	int	arg;

	stack_a = (int *)malloc(sizeof(int) * len);
	arg = 0;
	while (arg < len)
	{
		if (ft_is_numeric(argv[arg + 1]))
			stack_a[arg] = ft_atoi(argv[arg + 1]);
		else
		{
			free(stack_a);
			return (NULL);
		}
		arg++;
	}
	return (stack_a);
}
