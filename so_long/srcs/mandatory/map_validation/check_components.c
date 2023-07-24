/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:07:50 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 09:51:37 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_component_error(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Forbidden character!", 2);
}

int	check_characters(char *string, char *allowed)
{
	int		not_allowd;
	char	*temp;

	if (!string || !allowed)
		return (0);
	while (*string)
	{
		temp = allowed;
		not_allowd = 1;
		while (*temp)
		{
			if (*string == *temp)
			{
				not_allowd = 0;
				break ;
			}
			else
				temp++;
		}
		if (not_allowd == 1)
			return (print_component_error(), 0);
		string++;
	}
	return (1);
}

int	check_components(t_map *map)
{
	char	allowed[6];
	int		i;

	i = 0;
	allowed[0] = '0';
	allowed[1] = '1';
	allowed[2] = 'C';
	allowed[3] = 'E';
	allowed[4] = 'P';
	allowed[5] = '\0';
	while ((map->plan)[i])
	{
		if (!check_characters((map->plan)[i], allowed))
			return (0);
		i++;
	}
	return (1);
}
