/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 12:13:10 by oachbani          #+#    #+#             */
/*   Updated: 2025-01-28 12:13:10 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(t_map *map)
{
	size_t	len;
	int		cmp;

	len = ft_strlen(map->filename);
	cmp = ft_strncmp(map->filename + (len - 4), ".ber", 4);
	if (cmp != 0)
	{
		ft_putstr_fd("\033[31m map invalid it should end with .ber\n\033[0m", 2);
		exit(EXIT_FAILURE);
	}
}
