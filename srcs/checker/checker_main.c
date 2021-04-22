#include "checker.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int run;
	char *line;

	stack_a = str_to_int_arrays(argv, (argc - 1));
	run = 1;
	while (run)
	{
		run = get_next_line(1, &line);
	}
	return (0);
}
