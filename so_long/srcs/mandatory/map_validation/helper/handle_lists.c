/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:50:43 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/14 18:17:43 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_details	*find_last_node(t_details *head)
{
	if (!head)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

void	details_add_back(t_details **head, t_details *new)
{
	t_details	*last;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	last = find_last_node(*head);
	last->next = new;
}

t_details	*create_new_node(t_component component, int x, int y)
{
	t_details	*new;

	new = ft_calloc(1, sizeof(t_details));
	ft_bzero(new, sizeof(t_details));
	new->component = component;
	new->next = NULL;
	new->x = x;
	new->y = y;
	return (new);
}

int	get_list_length(t_details *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
