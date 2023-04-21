#include "push_swap.h"

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int get_valid_type(char c)
{
	if (c == '-' || c == '+') // is sign
		return 3;
	if (c >= '0' && c <= '9') // is numeric
		return 2;
	if (c == ' ' || c == '\0') // is separator
		return 1;
	return 0; // else is invalid
}

void	exit_with_message(char *msg, int error)
{
	write(1, "\n", 1); // I like separating the output from the input with a newline, but it might make the checker complain.
	if (error)
		write(1, msg, ft_strlen(msg));
	exit(error);
}

// This is like a standard atoi but if it encounters an overlfow error it exits the program with an error message.
// It also only accepts one sign and no leading spaces.
int ft_modified_atoi(char *str)
{
	int			i;
	long int	sign;
	long int	res;
	
	i = 0;
	sign = 1;
	res = 0;

	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	if ((i > 0) && (str[i - 1] == '-'))
		sign = -1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = (str[i] - '0') + (res * 10);
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			exit_with_message("INT overflow in input\n", 1);
		i++;
	}
	return ((int)(res * sign));
}
