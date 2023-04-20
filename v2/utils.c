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
	if (c == ' ' || c == '\0') // is space
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

int ft_atoi_with_exit(char *str)
{
	return (0);
}