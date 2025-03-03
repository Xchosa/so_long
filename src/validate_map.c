/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:33:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/03 14:06:38 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"



void validate_map(t_game game)
{
	int x;
	int y;
	int x_max;
	int y_max;
	x_max = game.x;
	y_max = game.y;
	x = 0;
	y = 0;
	if (!validate_edges_and_rect(game, x_max, y_max, x, y))
		exit(ft_printf("not rectangular"));
	// valid path yum collectiv und ziel
	// flood fill zum pruefen 
	// validate_path(t_game *game,  char *to_fill);
}

// validate_rectangular, and if map is surrounded by walls
int	validate_edges_and_rect(t_game game, int x_max, int y_max, int x, int y)
{
	while(game.map[0][y])
	{
		if((game.map[0][y] != '1') || (game.map[y_max -1][y]) != '1')
			return(ft_printf("error\n"));
		if((game.map[0][y] != '\0') || (game.map[y_max -1][y]) != '\0')
			return(ft_printf("not rectangular"));
		y++;
	}
	while(x < x_max )
	{
		if(((game.map[x][0]) != '1') || (game.map[x][y_max -1] != '1'))
			return(ft_printf("error map wall\n"));
		if(((game.map[x][0]) != '\0') || (game.map[x][y_max -1] != '\0'))
			return(ft_printf("not rectangular"));
		x++;
	}
	return(EXIT_SUCCESS);
}

// raender alle 1 check 
	// mind 1 collectiv
	
	// ein exit 
	// rechteckig - jede zeile und spalte gleich lang \\ check 
	// valid path yum collectiv und ziel
	// flood fill zum pruefen 

void	fill(t_game game, char to_fill)
{
	if (game.y < 0 || game.y >= size.y || game.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	validate_path(t_game *game,  char *to_fill)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}


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

