/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils_itoa.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 12:40:22 by limartin      #+#    #+#                 */
/*   Updated: 2021/04/26 12:56:41 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static	size_t	ft_intlen(long int num)
{
	size_t		len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	long int	num;
	size_t		len;
	size_t		i;
	char		*res;

	num = n;
	len = ft_intlen(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	i = 0;
	if (n < 0)
	{
		res[i] = '-';
		num *= -1;
		i++;
	}
	res[len] = '\0';
	while (len != i)
	{
		len--;
		res[len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

char	**int_array_to_strs(int *array, int len)
{
	char	**stack_a;
	int		arg;

	stack_a = (char **)malloc(sizeof(char *) * (len + 1))
	if (stack_a == NULL)
		return (NULL);
	stack_a[len] = NULL;
	arg = 0;
	while (arg < len)
	{
		stack_a[arg] = ft_itoa(array[arg]);
	}
	return (stack_a);
}
