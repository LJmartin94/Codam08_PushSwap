#include "push_swap.h"

void parse_input_as_string(t_data *d, char *input_string)
{
	int i;
	int type;
	int j;

	i = 0;
	d->num_of_args = 0;
	while(input_string[i] != '\0')
	{
		type = get_valid_type(input_string[i]);
		if (type == 3 && (get_valid_type(input_string[i + 1]) != 2)) //sign not followed by a digit
			exit_with_message("Invalid signs in input\n", 1);
		else if (type == 2 && get_valid_type(input_string[i + 1]) == 1) //digit is followed by a space or '\0'
			d->num_of_args++;
		else if (type == 0) //something invalid was encountered
			exit_with_message("Invalid input\n", 1);
		i++;
	} //done with parsing (checking invalid chars etc)
	d->input = (int*)malloc(sizeof(int) * d->num_of_args); //store result
	i = 0;
	j = 0;
	while(i < d->num_of_args)
	{
		while (get_valid_type(input_string[j]) == 1 \
			&& get_valid_type(input_string[j]) != 2)
			j++;
		d->input[i] = ft_modified_atoi(&(input_string[j]));
		i++;
	}
}

void parse_input_as_array(t_data *d, char **argv)
{
	int i;
	int j;

	i = 0;
	while(i < d->num_of_args)
	{
		j = 0;
		while(argv[1 + i][j] != '\0')
		{
			if (get_valid_type(argv[1 + i][j]) == 3 \
				&& (get_valid_type(argv[1 + i][j + 1]) != 2)) //sign not followed by a digit
				exit_with_message("Invalid signs in input\n", 1);
			else if (get_valid_type(argv[1 + i][j]) == 0) //something invalid was encountered
				exit_with_message("Invalid input\n", 1);
			j++;
		}
		i++;
	} //done with parsing (checking invalid chars etc)
	d->input = (int*)malloc(sizeof(int) * d->num_of_args);
	i = 0;
	while(i < d->num_of_args)
	{
		d->input[i] = ft_modified_atoi(argv[1 + i]);
		i++;
	}
}

void parsing(t_data *d, int argc, char **argv)
{
	if (argc < 2)
		exit_with_message("Not enough arguments supplied\n", 1);
	else if (argc == 2)
		parse_input_as_string(d, argv[1]);
	else // argc > 2 implied.
	{
		d->num_of_args = argc - 1; //we pass modified argc! We want it to count number of ints we need to store.
		parse_input_as_array(d, argv); 
	}
}