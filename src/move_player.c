/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:22:10 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/10 09:47:33 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	ft_escape_key(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	
	game = (t_game *) param;
	
	ft_printf("postion player start  y  : %d\n", game->player_yx[0]);
	ft_printf("position player start x  : %d \n", game->player_yx[1]);
	
	if(keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		move_player_y_x(-1, 0, game, game->image);
	if(keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move_player_y_x(0, -1, game, game->image);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move_player_y_x(1, 0, game, game->image);
	if (keydata.key == MLX_KEY_D  && keydata.action == MLX_RELEASE)
		move_player_y_x(0, 1, game, game->image);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit(1);
	}
}
// addional win and loose
// sith walk around, if u touch them, u loose
// time with 30 s going down, after that loose 

void	move_player_y_x(int y, int x, t_game *game, t_img *image)
{
	int	new_x;
	int	new_y;
	new_y = game->player_yx[0]+ y;
	new_x = game->player_yx[1]+ x;
	ft_printf("postion player new_y : %d\n", new_y);
	ft_printf("position player new_x  : %d \n", new_x);
	if (game->map[new_y][new_x] == WALL)
		return;
	if (game->map[new_y][new_x] == COLLECTIBLES)
	{
		game->collectables++;
		if (game->collectables == game->collectables_check)
			game->exit_unlocked = true;
		mlx_image_to_window(game->mlx, image->spirit, new_x * Pixel, new_y * Pixel);
		mlx_image_to_window(game->mlx, image->background, game->player_yx[1] * Pixel, game->player_yx[0]* Pixel);
	} 
	if (game->map [new_y][new_x] == EXIT)
	{
		if(game->exit_unlocked == true)
		{
			mlx_image_to_window(game->mlx, image->spirit, new_x * Pixel, new_y * Pixel);
			exit(printf("exit success"));
		return; // can not move over exit
	}
	if (game->map[new_y][new_x] == BACKGROUND)
		mlx_image_to_window(game->mlx, image->spirit, new_x * Pixel, new_y * Pixel);
		mlx_image_to_window(game->mlx, image->background, game->player_yx[1] * Pixel, game->player_yx[0]* Pixel);
	game->player_yx[1]= new_x;
	game->player_yx[0]= new_y;
	
	game->moves_nbr++;
	ft_printf("moves: %d \n", game->moves_nbr);
	ft_printf("postion player start  y after move : %d\n", new_y);
	ft_printf("position player start x after move : %d \n", new_x);
}

