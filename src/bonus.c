/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:23:59 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/17 13:09:04 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

// void	bonus_droide(t_game *game)
// {
// 	int droide_x;
// 	int droide_y;
// 	int prev_droide_y;
// 	prev_droide_y = 0;

// 	droide_x = 10;
// 	if (game->moves_nbr % 6 < 3)
// 		droide_y = 2 + (game->moves_nbr % 3);
// 	else
// 		droide_y = 4 - (game->moves_nbr % 3);
// 	game->map[droide_x][droide_y] = DROIDE;
// 	mlx_image_to_window(game->mlx, game->image->droide, droide_x * PIXEL,
// 			 droide_y * PIXEL);
// 	if (game->moves_nbr > 0)
//     {
//         if ((game->moves_nbr - 1) % 6 < 3)
//             prev_droide_y = 2 + ((game->moves_nbr - 1) % 3);
//         else
//             prev_droide_y = 4 - ((game->moves_nbr - 1) % 3);
// 	}
// 	if (game->map[droide_x][prev_droide_y] == DROIDE)
// 		print_loose(game, game->image);
// 	else 
// 		game->map[droide_x][prev_droide_y] = BACKGROUND;
//    		mlx_image_to_window(game->mlx, game->image->background,
// 			droide_x * PIXEL, prev_droide_y * PIXEL);
//     return;
// }

// void print_loose (t_game *game, t_img *image)
// {
// 	mlx_image_to_window(game->mlx, image->loose, 0.1 * PIXEL, 0.2 * PIXEL);
// 	game->finished = true;
// 	return ;
// }

// void	move_player_y_x(int y, int x, t_game *game, t_img *image)
// {
// 	int	new_x;
// 	int	new_y;
//
// 	new_y = game->player_yx[0] + y;
// 	new_x = game->player_yx[1] + x;
// 	if (game->finished == true)
// 		terminate_game(game, image);
// 	if (game->map[new_y][new_x] == DROIDE)
// 	{
// 		print_loose(game, image);
// 		return ;
// 	}
// 	if (game->map[new_y][new_x] == WALL)
// 		return ;
// 	if (game->map[new_y][new_x] == COLLECTIBLES)
// 	{
// 		game->collectables++;
// 		if (game->collectables == game->collectables_check)
// 			game->exit_unlocked = true;
// 		set_image_player(game, image, new_x, new_y);
// 	}
// 	if (game->map [new_y][new_x] == EXIT)
// 	{
// 		print_success(new_x, new_y, game, image);
// 		return ;
// 	}
// 	if (game->map[new_y][new_x] == BACKGROUND)
// 		set_image_player(game, image, new_x, new_y);
// 	bonus_droide(game);
// 	set_player_nbr_moves(game, new_x, new_y);
// }
//
// // atexit(leaks);
// void	leaks(void)
// {
// 	ft_printf("\n");
// 	system("leaks so_long");
// }
