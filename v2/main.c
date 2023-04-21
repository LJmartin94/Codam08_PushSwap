#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_data d;

	d.input = NULL;
	parsing(&d, argc, argv);


	for (int i = 0; i < d.num_of_args; i++)
		printf("%d ", d.input[i]);
	
	return 0;
}