/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:22:10 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/07 16:40:04 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	ft_escape_key(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	
	game = (t_game *) param;
	
	game->moves_nbr++;
	ft_printf("moves: %d \n", game->moves_nbr);
	
	if(keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		move_player_y_x(1, 0, game, game->image);
	if(keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move_player_y_x(0, -1, game, game->image);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move_player_y_x(-1, 0, game, game->image);
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
	new_x = game->player_start_yx[1]+ x;
	new_y = game->player_start_yx[0]+ y;
	ft_printf("position player start x move : %d \n", game->player_start_yx[1]);
	ft_printf("postion player start  y move : %d\n", game->player_start_yx[0]);
	if (game->map[new_y][new_x] == WALL)
		return;
	if (game->map[new_y][new_x] == COLLECTIBLES) // pls change typo
	{
		game->collectables++;
		if (game->collectables == game->collectables_check) // reset collectables_check OR collectables 
			game->exit_unlocked = true;
		mlx_image_to_window(game->mlx, image->spirit, new_x * Pixel, new_y * Pixel);
		mlx_image_to_window(game->mlx, image->background, game->player_start_yx[1] * Pixel, game->player_start_yx[0]* Pixel);
	} 
	if (game->map [new_y][new_x] == EXIT)
	{
		if(game->exit_unlocked == true)
			exit(printf("exit success")); // need picture for winning to display in the middle
		return; // can not move over exit
	}
	if (game->map[y][x] == BACKGROUND)
		mlx_image_to_window(game->mlx, image->spirit, new_x * Pixel, new_y * Pixel);
		mlx_image_to_window(game->mlx, image->background, game->player_start_yx[1] * Pixel, game->player_start_yx[0]* Pixel);
	// put player next postion 
	// img randern auf diesem feld
	game->player_start_yx[1]= new_x;
	game->player_start_yx[0]= new_y;
	ft_printf("check seq after move %d \n", new_x);
	ft_printf("check seq after move %d \n", new_y);

}


// void success(img img ) // 	import image
// {
// 	mlx_image_to_window(game->mlx, image->Background, new_x * Pixel, new_y* Pixel );	x2?
// 	exit(1)
// }


// if (game->map[y][x] == BACKGROUND)
// 	mlx_image_to_window(game->mlx, image->background, x * Pixel, y * Pixel);
// if (game->map[y][x] == PLAYER)
// 	mlx_image_to_window(game->mlx, image->spirit, x * Pixel, y * Pixel);

// 	image->background = mlx_texture_to_image(game->mlx, texture->background);
// 	image->wall = mlx_texture_to_image(game->mlx, texture->wall);
// 	image->collectives = mlx_texture_to_image(game->mlx, texture->collectives);
// 	image->exit = mlx_texture_to_image (game->mlx, texture->exit);
// 	image->spirit = mlx_texture_to_image (game->mlx, texture->spirit);
