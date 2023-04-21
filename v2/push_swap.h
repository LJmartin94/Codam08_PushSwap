#include <stdlib.h> //exit
#include <unistd.h> //write

//data struct -> anything that is malloc'd and needs to be freed goes in here.
typedef struct s_data
{
	int *input;
} t_data;

//utils.c
int		ft_strlen(const char *str);
void	exit_with_message(char *msg, int error);
int		ft_atoi_with_exit(char *str);
int		get_valid_type(char c);

//parsing.c
void	parsing(t_data d, int argc, char **argv);