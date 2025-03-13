/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_to_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:58:28 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/13 15:21:19 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

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
	game->image = malloc(sizeof(t_img));
	if (!game->image)
    {
        ft_printf("Failed to allocate memory for game->image");
        exit(1);
    }
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
	if (!game->mlx)
    {
        ft_printf("Error \nFailed to initialize MLX");
        exit(EXIT_FAILURE);
    }
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
