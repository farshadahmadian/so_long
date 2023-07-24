/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:44:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:26:41 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
