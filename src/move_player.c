/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:22:10 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/06 15:44:56 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	ft_escape_key(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	// param - das bild was jedes mal neu reingegeben wird 
	game = (t_game *) param;
	if(keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		move_player_y_x(1, 0, game);
	if(keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move_player_y_x(0, -1, game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move_player_y_x(-1, 0, game);
	if (keydata.key == MLX_KEY_D  && keydata.action == MLX_RELEASE)
		move_player_y_x(0, 1, game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit(1);
	}
}


// MLX_KEY_RIGHT			= 262,
// 	MLX_KEY_LEFT			= 263,
// 	MLX_KEY_DOWN			= 264,
// 	MLX_KEY_UP				= 265,


void move_player_y_x(int y, int x, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_start_yx[1]+ x;
	new_y = game->player_start_yx[0]+ y;
	if (game->map[new_y][new_x] == WALL)
		return;
	if (game->map[y][x] == BACKGROUND);
		mlx_image_to_window(game->mlx, image->spirit, x * Pixel, y * Pixel);
	// put player next postion 
	// img randern auf diesem feld
	
	// if (game->map[y][x] == EXIT);
	// {
	// 	if (game.exit_unlocked)
	//	exit;
	//	}
	game->player_start_yx[1]= new_x;
	game->player_start_yx[0]= new_y;
	// space 
	game->moves_nbr++;
	ft_printf("Moves made: %d\n", game->moves_nbr);
	mlx_image_to_window(game->mlx, game->map, game->x, game->y);
	put_picture()
}



