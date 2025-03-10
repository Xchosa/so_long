/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:09:47 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/10 09:40:57 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	get_map(char *map_name, t_game *game)
{
	int fd;
	char *map_line;
	char *joined_line;
	joined_line = "";
	game->y = 0;
	fd = open(map_name, O_RDONLY );
	if(!fd)
		exit(EXIT_FAILURE);
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		joined_line = ft_strjoin(joined_line, map_line);
		free(map_line);
		map_line = get_next_line(fd);
		game->y++;
	}
	validate_characters_general(joined_line);// exit and frees if fail
	ft_printf("%s\n",joined_line);
	game->map = ft_split(joined_line, '\n'); // 
	game->copy_map = ft_split(joined_line, '\n');
	game->collectables = count_collectables(joined_line);
	game->x = ft_strlen(game->map[0]);
	free(joined_line);
}


void fill_texture_image(t_texture *texture, t_game *game)
{
	texture->background = mlx_load_png("./img/background_star.png");
	texture->wall = mlx_load_png("./img/star_space.png");
	texture->collectives = mlx_load_png("./img/R2_D2.png");
	texture->exit = mlx_load_png("./img/ship.png");
	texture->spirit = mlx_load_png("./img/yoda.png");
	
	game->image->background = mlx_texture_to_image(game->mlx, texture->background);
	game->image->wall = mlx_texture_to_image(game->mlx, texture->wall);
	game->image->collectives = mlx_texture_to_image(game->mlx, texture->collectives);
	game->image->exit = mlx_texture_to_image (game->mlx, texture->exit);
	game->image->spirit = mlx_texture_to_image (game->mlx, texture->spirit);
	
}
 

void render_map(t_game *game, t_texture *texture)
{
	int x;
	int y;
	y = 0;
	game->mlx = mlx_init(Pixel * game->x, Pixel * game->y, "so_long", false);
	fill_texture_image(texture, game);
	while (game->map[y]) // x noch \0 , darf nicht geprueft werde 
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALL)
				mlx_image_to_window(game->mlx, game->image->wall, x * Pixel, y * Pixel);
			if (game->map[y][x] == BACKGROUND)
				mlx_image_to_window(game->mlx, game->image->background, x * Pixel, y * Pixel);
			if (game->map[y][x] == PLAYER)
				mlx_image_to_window(game->mlx, game->image->spirit, x * Pixel, y * Pixel);
			if (game->map[y][x] == EXIT)
				mlx_image_to_window(game->mlx, game->image->exit, x * Pixel, y * Pixel);
			if (game->map[y][x] == COLLECTIBLES)
				mlx_image_to_window(game->mlx, game->image->collectives, x * Pixel, y * Pixel);
			x++;
		}
		y++;
	}
}



