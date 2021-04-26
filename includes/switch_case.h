/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   switch_case.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lindsay <lindsay@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 21:47:53 by lindsay       #+#    #+#                 */
/*   Updated: 2021/04/26 12:27:52 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWITCH_CASE_H
# define SWITCH_CASE_H

typedef struct s_switch_obj
{
	void	*condition;
	void	*res;
}	t_switch_obj;

#endif