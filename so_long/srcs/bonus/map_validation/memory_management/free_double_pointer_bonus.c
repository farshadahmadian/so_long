/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_pointer_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:45:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:26:35 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
