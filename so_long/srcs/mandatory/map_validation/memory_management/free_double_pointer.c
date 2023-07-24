/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:45:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/14 19:38:55 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_pointer(char **ptr, int i)
{
	if (!ptr)
		return ;
	while (i >= 0)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i--;
	}
	free (ptr);
	ptr = NULL;
}
