/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 01:09:44 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/29 21:45:06 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_link *to_print)
{
	t_link	*tmp;

	tmp = to_print;
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->below;
	}
	printf("\n");
	return ;
}
