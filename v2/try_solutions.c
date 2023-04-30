/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_solutions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 16:12:07 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/30 16:26:18 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	try_solutions(t_data *d)
{
	d->solutions = (t_link **)malloc(sizeof(t_link *) * SOLUTIONS_TOTAL);
	d->solutions[DUMB_SORT] = dumb_sort(d);
}