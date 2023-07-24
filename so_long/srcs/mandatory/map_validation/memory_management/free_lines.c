/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:44:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/14 19:39:52 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_list *head, void (*free_content)(t_list *current_node))
{
	t_list	*temp;

	if (!head)
		return ;
	temp = head;
	while (head)
	{
		temp = head;
		free_content(temp);
		head = head->next;
		free(temp);
	}
}
