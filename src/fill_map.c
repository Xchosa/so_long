/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:09:47 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/11 17:46:33 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	get_map(char *map_name, t_game *game)
{
	int		fd;
	char	*map_line;
	char	*joined_line;
	char	*tmp

	joined_line = "";
	// joined_line = malloc(sizeof(char));
	game->y = 0;
	fd = open(map_name, O_RDONLY);
	if (!fd)
		gnl_exit ("Could not read map", fd);
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		printf("joined line%p \n", joined_line);
		tmp = ft_strdup(joined_line);
		joined_line = ft_strjoin(tmp, map_line);
		free(map_line);
		map_line = get_next_line(fd);
		game->y++;

	}
	validate_characters_general(joined_line);
	game->map = ft_split(joined_line, '\n');
	game->copy_map = ft_split(joined_line, '\n');
	if ((!game->map) || (!game->copy_map))
		faild_split("failed split", game);
	game->collectables = count_collectables(joined_line, game);
	game->x = ft_strlen(game->map[0]);
	return (free(joined_line), close(fd), (void)0);
}

void	ft_image_to_window(int y, int x, t_game *game)
{
	if (game->map[y][x] == WALL)
		mlx_image_to_window(game->mlx, game->image->wall,
			x * PIXEL, y * PIXEL);
	if (game->map[y][x] == BACKGROUND)
		mlx_image_to_window(game->mlx, game->image->background,
			x * PIXEL, y * PIXEL);
	if (game->map[y][x] == PLAYER)
		mlx_image_to_window(game->mlx, game->image->spirit,
			x * PIXEL, y * PIXEL);
	if (game->map[y][x] == EXIT)
		mlx_image_to_window(game->mlx, game->image->exit,
			x * PIXEL, y * PIXEL);
	if (game->map[y][x] == COLLECTIBLES)
		mlx_image_to_window(game->mlx, game->image->collectives,
			x * PIXEL, y * PIXEL);
}

void	fill_texture_image(t_texture *texture, t_game *game)
{
	if (!game->mlx)
		mlx_terminate(game->mlx);
	texture->background = mlx_load_png("./img/background_star.png");
	texture->wall = mlx_load_png("./img/star_space.png");
	texture->collectives = mlx_load_png("./img/R2_D2.png");
	texture->exit = mlx_load_png("./img/ship.png");
	texture->spirit = mlx_load_png("./img/yoda.png");
	texture->win = mlx_load_png("./img/win_game.png");
	texture->droide = mlx_load_png("./img/Droide.png");
	texture->loose = mlx_load_png("./img/Loose.png");
	put_images(texture, game);
}

void	put_images(t_texture *texture, t_game *game)
{
	game->image->background = mlx_texture_to_image(game->mlx,
			texture->background);
	game->image->wall = mlx_texture_to_image(game->mlx,
			texture->wall);
	game->image->collectives = mlx_texture_to_image(game->mlx,
			texture->collectives);
	game->image->exit = mlx_texture_to_image (game->mlx, texture->exit);
	game->image->spirit = mlx_texture_to_image (game->mlx, texture->spirit);
	game->image->win = mlx_texture_to_image (game->mlx, texture->win);
	game->image->droide = mlx_texture_to_image (game->mlx, texture->droide);
	game->image->loose = mlx_texture_to_image (game->mlx, texture->loose);
}

void	render_map(t_game *game, t_texture *texture)
{
	int	x;
	int	y;

	y = 0;
	game->mlx = mlx_init(PIXEL * game->x, PIXEL * game->y, "so_long", false);
	fill_texture_image(texture, game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_image_to_window(y, x, game);
			x++;
		}
		y++;
	}
}
