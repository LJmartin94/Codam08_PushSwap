/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:41:00 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/21 21:28:34 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input_as_string(t_data *d, char *input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i] != '\0')
	{
		if ((get_type(input[i]) == 3 && get_type(input[i + 1]) != 2) \
			|| get_type(input[i]) == 0)
			exit_with_message("Invalid input\n", 1);
		else if (get_type(input[i]) == 2 && get_type(input[i + 1]) == 1)
			d->num_of_args++;
		i++;
	}
	d->input = (int *)malloc(sizeof(int) * d->num_of_args);
	i = 0;
	j = 0;
	while (i < d->num_of_args)
	{
		d->input[i] = ft_modified_atoi(&(input[j]));
		while (get_type(input[j]) == 2)
			j++;
		while (get_type(input[j]) == 1)
			j++;
		i++;
	}
}

void	parse_input_as_array(t_data *d, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->num_of_args)
	{
		j = 0;
		while (argv[1 + i][j] != '\0')
		{
			if (get_type(argv[1 + i][j]) == 3 \
				&& (get_type(argv[1 + i][j + 1]) != 2))
				exit_with_message("Invalid signs in input\n", 1);
			else if (get_type(argv[1 + i][j]) == 0)
				exit_with_message("Invalid input\n", 1);
			j++;
		}
		i++;
	}
	d->input = (int *)malloc(sizeof(int) * d->num_of_args);
	i = 0;
	while (i < d->num_of_args)
	{
		d->input[i] = ft_modified_atoi(argv[1 + i]);
		i++;
	}
}

void	parsing(t_data *d, int argc, char **argv)
{
	if (argc < 2)
		exit_with_message("Not enough arguments supplied\n", 1);
	else if (argc == 2)
		parse_input_as_string(d, argv[1]);
	else
	{
		d->num_of_args = argc - 1;
		parse_input_as_array(d, argv);
	}
}
