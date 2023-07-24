/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_details_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:39:55 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:26:45 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_t_details(t_details *head)
{
	t_details	*temp;

	if (!head)
		return ;
	temp = head;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
