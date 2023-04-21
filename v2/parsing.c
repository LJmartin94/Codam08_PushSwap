#include "push_swap.h"

void parse_input_as_string(t_data *d, int num_of_args, char *input_string)
{
	int i;
	int type;

	i = 0;
	num_of_args = 0;
	while(input_string[i] != '\0')
	{
		type = get_valid_type(input_string[i]);
		if (type == 3 && (get_valid_type(input_string[i + 1]) != 2)) //sign not followed by a digit
			exit_with_message("Invalid signs in input\n", 1);
		else if (type == 2 && get_valid_type(input_string[i + 1]) == 1) //digit is followed by a space or '\0'
			num_of_args++;
		else if (type == 0) //something invalid was encountered
			exit_with_message("Invalid input\n", 1);
		i++;
	} //done with parsing
	d->input = (int*)malloc(sizeof(int) * num_of_args); //store result
	i = 0;
}

void parse_input_as_array(t_data *d, int num_of_args, char **argv)
{
	int i;

	i = 0;
	while(i < num_of_args)
	{

	} //done with parsing
	d->input = (int*)malloc(sizeof(int) * num_of_args);
	i = 0;
	while(i < num_of_args)
	{
		d->input[i] = ft_atoi_with_exit(argv[1 + i]); //we skip past the first argv, because it's the program name.
	}
}

void parsing(t_data *d, int argc, char **argv)
{
	if (argc < 2)
		exit_with_message("Not enough arguments supplied\n", 1);
	else if (argc == 2)
		parse_input_as_string(d, argc, argv[1]);
	else // argc > 2 implied.
		parse_input_as_array(d, argc - 1, argv);
}