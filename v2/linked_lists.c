/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_lists.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 21:49:29 by limartin      #+#    #+#                 */
/*   Updated: 2023/04/28 13:50:12 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_list(t_link *to_count)
{
	t_link	*tmp;
	int		ret;

	ret = 0;
	tmp = to_count;
	while (tmp)
	{
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}

t_link	*new_node(t_data *d, int content)
{
	t_link	*ret;

	ret = (t_link *)malloc(sizeof(t_link));
	if (ret == NULL)
		exit_with_message(d, "Malloc fail\n", 1);
	ret->content = content;
	ret->next = NULL;
	ret->previous = NULL;
	return (ret);
}

t_link	*add_to_back(t_link *head, t_link *to_add)
{
	t_link	*tmp;

	tmp = head;
	if (tmp == NULL)
	{
		head = to_add;
		return (head);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
	to_add->previous = tmp;
	return (head);
}

t_link	*copy_list(t_data *d, t_link *to_copy)
{
	t_link	*ret;
	t_link	*tmp;

	ret = NULL;
	tmp = to_copy;
	while(tmp)
	{
		ret = add_to_back(ret, new_node(d, tmp->content));
		tmp = tmp->next;
	}
	return ret;
}
