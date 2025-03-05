/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:54:00 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/05 16:48:53 by poverbec         ###   ########.fr       */
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




// // start punkt vom player uebergeben

// void	fill(char **tab, t_point size, t_point cur, char to_fill)
// {
// 	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
// 		|| tab[cur.y][cur.x] != to_fill)
// 		return ;
// 	tab[cur.y][cur.x] = 'F';
// 	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
// }

// void	flood_fill(char **tab,  size, t_point begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }



void	flood_fill(t_game *game, int *start_of_player)
{
	// start_point  uebergeben;
	int x = game->player_start[1];
	int y = game->player_start[0];
	
	// zwei zu fill 
	// check if Exit has neigbouring F
	// ft_printf("x.game %d ", game.x);
	if ((game->copy_map[y][x] == 'X') || (game->copy_map[y][x] == '1'))
		return ;
	if (game->copy_map[y][x] == 'E')
	{
		game->map_exit == true;
		return ;
	}
	if (game->copy_map[y][x] == 'C')
		game->collectables_check++;
	game->copy_map[y][x] == 'X';
	
	// collect collectibles 
	floodfill(x, y + 1, game);
	floodfill(x, y - 1, game);
	floodfill(x + 1, y, game);
	floodfill(x -1, y, game);
}

void	validate_path(t_game *game, int y_max, int x_max)
{
	ft_printf("x.game %d ", game->x);
	flood_fill(game, game->player_start);
	if ((game->collectables) != (game.
	
	
}
