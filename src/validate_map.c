/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:33:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/03 16:45:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void find_start(t_game game)
{
	int y = 0;
	int x;
	while(game.map[y])
	{
		x = 0;
		while(game.map[y][x])
		{
			if(game.map[y][x] == 'P')
			{
				game.player_start[0] = y;
				game.player_start[1] = x;
				return;
			}
		x++;
		}
	}
	ft_printf("error");
}

void validate_map(t_game game)
{
	int x_max;
	int y_max;
	x_max = game.x;
	y_max = game.y;
	game.x = 0;
	game.y = 0;
	// find_start(game);
	validate_rectangular(game, y_max);
	if (validate_edge(game, x_max, y_max) == false)
		exit(ft_printf("not rectangular"));
	// valid path yum collectiv und ziel
	// flood fill zum pruefen 
	validate_path(&game, y_max, x_max);
}

// validate_rectangular, and if map is surrounded by walls
int	validate_edge(t_game game, int x_max, int y_max)
{
	int x;
	int y;
	x = 0;
	y = 0;
	while(game.map[y][0])
	{
		if((game.map[y][0] != '1') || (game.map[y][y_max -1]) != '1')
			return(ft_printf("error\n"));
		y++;
	}
	while(x < x_max )
	{
		if(((game.map[0][x]) != '1') || (game.map[y_max-1][x] != '1'))
			return(ft_printf("error map wall\n"));
		x++;
	}
	return(true);
}
void	validate_rectangular(t_game game, int y_max )
{
	int y = 0;
	int current_row_length;
	int first_row_length= ft_strlen(game.map[0]);
	while(y < y_max)
	{
		current_row_length = ft_strlen(game.map[y]);
		if (current_row_length !=  first_row_length)
		{
			ft_printf("not rectangular");
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

// if(((game.map[x][0]) != '\0') || (game.map[x][y_max -1] != '\0'))
// 			return(ft_printf("not rectangular"));

// raender alle 1 check 
	// mind 1 collectiv
	
	// ein exit 
	// rechteckig - jede zeile und spalte gleich lang \\ check 
	// valid path yum collectiv und ziel
	// flood fill zum pruefen 


	
void	flood_fill(t_game *game, int player_start)
{
	// start_point  uebergeben;
	int x = game->player_start[1];
	int y = game->player_start[0];
	
	// zwei zu fill 
	// check if Exit has neigbouring F
	// ft_printf("x.game %d ", game.x);
	if (game.y < 0 || game.y >= y_max || game.x < 0 || game.x >= x_max
		|| game.map[x][y] != '0'  || game.map[x][y] != 'C')
		return ;
	game.map[x][y] = 'F';// filled 
	
	// collect collectibles 
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	validate_path(t_game *game, int y_max, int x_max)
{
	ft_printf("x.game %d ", game->x);
	flood_fill(game, game->player_start);
	
}





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



int validate_characters_general(char *joined_line)
{
	int i;
	i = 0;
    while (joined_line[i] != '\0')
    {
        if (joined_line[i] != '0' && joined_line[i] != '1' &&
            joined_line[i] != 'P' && joined_line[i] != 'E' &&
            joined_line[i] != 'C' && joined_line[i] != '\n')
        {
            return EXIT_FAILURE; 
        }
        i++;
    }
    return EXIT_SUCCESS; 
}

