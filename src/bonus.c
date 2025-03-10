/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:23:59 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/10 15:26:26 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	bonus_droide(t_game *game)
{
	int droide_x;
	int droide_y;
	int prev_droide_y;
	
	droide_x = 10;
	if (game->moves_nbr % 6 < 3)
		droide_y = 2 + (game->moves_nbr % 3);
	else
		droide_y = 4 - (game->moves_nbr % 3);
	mlx_image_to_window(game->mlx, game->image->droide, droide_x * Pixel, droide_y * Pixel);
	
	if (game->moves_nbr > 0)
    {
        if ((game->moves_nbr - 1) % 6 < 3)
            prev_droide_y = 2 + ((game->moves_nbr - 1) % 3);
        else
            prev_droide_y = 4 - ((game->moves_nbr - 1) % 3);
        mlx_image_to_window(game->mlx, game->image->background, droide_x * Pixel, prev_droide_y * Pixel);
    }
    return;
}

void print_loose (int new_x, int new_y, t_game *game, t_img *image)
{
	set_image_player(game, image, new_x, new_y);
	mlx_image_to_window(game->mlx, image->loose, 3 * Pixel, 3 * Pixel);
	game->finished = true;
	return ;
}

