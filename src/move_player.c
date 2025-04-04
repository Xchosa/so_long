/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:22:10 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/17 13:16:58 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	ft_escape_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		move_player_y_x(-1, 0, game, game->image);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move_player_y_x(0, -1, game, game->image);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move_player_y_x(1, 0, game, game->image);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		move_player_y_x(0, 1, game, game->image);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		terminate_game(game, game->image);
	}
}

void	move_player_y_x(int y, int x, t_game *game, t_img *image)
{
	int	new_x;
	int	new_y;

	new_y = game->player_yx[0] + y;
	new_x = game->player_yx[1] + x;
	if (game->finished == true)
		terminate_game(game, image);
	if (game->map[new_y][new_x] == WALL)
		return ;
	if (game->map[new_y][new_x] == COLLECTIBLES)
	{
		game->collectables++;
		if (game->collectables == game->collectables_check)
			game->exit_unlocked = true;
		set_image_player(game, image, new_x, new_y);
	}
	if (game->map [new_y][new_x] == EXIT)
	{
		print_success(new_x, new_y, game, image);
		return ;
	}
	if (game->map[new_y][new_x] == BACKGROUND)
		set_image_player(game, image, new_x, new_y);
	set_player_nbr_moves(game, new_x, new_y);
}

void	print_success(int new_x, int new_y, t_game *game, t_img *image)
{
	if (game->exit_unlocked == true)
	{
		set_image_player(game, image, new_x, new_y);
		if (game->x < 5)
			mlx_image_to_window(game->mlx, image->win,
				0.1 * PIXEL, 0.1 * PIXEL);
		else
			mlx_image_to_window(game->mlx, image->win,
				game->x / 2 * PIXEL, 0.2 * PIXEL);
		game->finished = true;
		game->moves_nbr++;
		ft_printf("moves: %d \n", game->moves_nbr);
	}
	else
		return ;
}

void	set_player_nbr_moves(t_game *game, int new_x, int new_y)
{
	game->player_yx[1] = new_x;
	game->player_yx[0] = new_y;
	game->moves_nbr++;
	ft_printf("moves: %d \n", game->moves_nbr);
}

void	set_image_player(t_game *game, t_img *image, int new_x, int new_y )
{
	mlx_image_to_window(game->mlx, image->spirit, new_x * PIXEL, new_y * PIXEL);
	game->map[game->player_yx[0]][game->player_yx[1]] = BACKGROUND;
	game->map[new_y][new_x] = 'P';
	mlx_image_to_window(game->mlx, image->background,
		game->player_yx[1] * PIXEL, game->player_yx[0] * PIXEL);
}
