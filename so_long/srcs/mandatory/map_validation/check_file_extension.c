/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:30:14 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 09:36:26 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_extension_error(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Map extension is not valid!", 2);
}

int	check_file_extension(const char *file_dir, const char *extension)
{
	char	*dot_pointer;
	char	*founded_extension;
	size_t	extension_len;

	if (!file_dir || !extension)
		return (0);
	extension_len = ft_strlen(extension);
	dot_pointer = ft_strrchr(file_dir, '.');
	if (!dot_pointer)
	{
		print_extension_error();
		return (0);
	}
	founded_extension = ft_strnstr(dot_pointer + 1, extension, extension_len);
	if (founded_extension && *(dot_pointer + 1 + extension_len) == '\0')
		return (1);
	print_extension_error();
	return (0);
}
