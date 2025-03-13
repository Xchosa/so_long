/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:09:47 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/13 15:23:39 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	get_map(char *map_name, t_game *game)
{
	int		fd;
	char	*map_line;
	char	*joined_line;
	char	*tmp;

	joined_line = ft_strdup("");
	game->y = 0;
	fd = open(map_name, O_RDONLY);
	if (!fd)
		gnl_exit("Could not read map", joined_line, fd);
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		tmp = ft_strdup(joined_line);
		free(joined_line);
		joined_line = ft_strjoin(tmp, map_line);
		free(map_line);
		map_line = get_next_line(fd);
		game->y++;
		printf("%s | ", joined_line);
		printf("%p \n", joined_line);
	}
	validate_characters_general(joined_line, fd);
	fill_stack(joined_line, game, fd);
	return (free(joined_line), (void)0);
}

void	fill_stack(char *joined_line, t_game *game, int fd)
{
	game->map = ft_split(joined_line, '\n');
	game->copy_map = ft_split(joined_line, '\n');
	if ((!game->map) || (!game->copy_map))
		faild_split("failed split", game, fd);
	game->collectables = count_collectables(joined_line, game);
	game->x = ft_strlen(game->map[0]);
	close(fd);
}
