/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:54:00 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/06 12:58:02 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

// raender alle 1 check 
	// mind 1 collectiv
	
	// ein exit 
	// rechteckig - jede zeile und spalte gleich lang \\ check 
	// valid path yum collectiv und ziel
	// flood fill zum pruefen 


void	flood_fill(t_game *game, int y, int x)
{
	// start_point  uebergeben;
	
	// overwrite the copy of the map with X
	if ((game->copy_map[y][x] == 'X') || (game->copy_map[y][x] == '1'))
		return ;
	if (game->copy_map[y][x] == 'E')
	{
		game->map_exit = true;
	}
	if (game->copy_map[y][x] == 'C')
		game->collectables_check++;
	game->copy_map[y][x] = 'X';
	
	// collect collectibles 
	flood_fill(game, y + 1, x);
	flood_fill(game, y - 1, x);
	flood_fill(game, y, x + 1);
	flood_fill(game, y, x -1);
}
void	validate_path(t_game *game)
{
	game->collectables_check = 0;
	game->map_exit = false;
	ft_printf("count collectables %d \n", game->collectables);
	ft_printf("position player x %d \n", game->collectables_check);
	flood_fill(game, game->player_start[0], game->player_start[1]);
	if ((game->collectables) != (game->collectables_check))
	{
		validate_error_map("Not all collectables are reachable", *game);
	}
	if (game->map_exit == false)
	{
		validate_error_map("exit not reachable", *game);
	}
}


// for keyhook
