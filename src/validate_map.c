/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:33:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/05 13:23:40 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"


void validate_characters_general(char *joined_line)
{
	int i;
	i = 0;
	while (joined_line[i] != '\0')
    {
        if (joined_line[i] != '0' && joined_line[i] != '1' &&
            joined_line[i] != 'P' && joined_line[i] != 'E' &&
            joined_line[i] != 'C' && joined_line[i] != '\n')
        	{
				free(joined_line);
           		exit(ft_printf("Map with wrong input: %s", joined_line[i])); 
        	}
        i++;
    }
	count_player(joined_line);
}

void count_player(char *map_as_string)
{
	int count_player;
	int i;
	i = 0;
	count_player = 0;
	while (map_as_string[i] != '\0')
	{
		if (map_as_string[i] == 'P')
			count_player++;
		i++;
	}
	if (count_player == 0 )
	{
		free(map_as_string);
		exit(ft_printf("error/n No player found"));
	}
	if (count_player == 2 )
	{
		free(map_as_string);
		exit(ft_printf("error/n %d player found", count_player));
	}
}
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
		y++;
	}
	exit(ft_printf("error/n could not find Starting Point of Player"));
}

int count_collectables(char *game_as_string)
{
	int count_collectables;
	int i;
	i = 0;
	count_collectables = 0;
	while (game_as_string[i])
	{
		if (game_as_string[i] == 'C')
			count_collectables++;
		i++;
	}
	if (count_collectables == 0)
		ft_printf("error\n No collectiables found");
	return(count_collectables);
}

bool	validate_edge(t_game game, int x_max, int y_max)
{
	int x;
	int y;
	x = 0;
	y = 0;
	bool bool_edges;
	bool_edges = true;
	while(y < y_max)
	{
		if((game.map[y][0] != '1') || (game.map[y][x_max-1]) != '1')
		{
			ft_printf("error \nmap wall ");
			return(bool_edges = false);
		}
		y++;
	}
	while(x < x_max )
	{
		if(((game.map[0][x]) != '1') || (game.map[y_max-1][x] != '1'))
		{
			ft_printf("error \nmap wall\n");
			return(bool_edges = false);
		}
		x++;
	}
	return(bool_edges);
}



// validate_rectangular, and if map is surrounded by walls
bool	validate_rectangular(t_game game, int y_max )
{
	bool bool_rectangular;
	bool_rectangular = true;
	int y = 0;
	int current_row_length;
	int first_row_length= ft_strlen(game.map[0]);
	while(y < y_max)
	{
		current_row_length = ft_strlen(game.map[y]);
		if (current_row_length !=  first_row_length)
		{
			ft_printf("error\n Map not rectangular");
			return(bool_rectangular = false);
		}
		y++;
	}
	return (bool_rectangular);
}

void validate_map(t_game game)
{
	int x_max;
	int y_max;
	x_max = game.x;
	y_max = game.y;
	game.x = 0;
	game.y = 0;
	find_start(game);
	validate_rectangular(game, y_max);
	if ((validate_edge(game, x_max, y_max) == false) || (validate_rectangular(game, y_max) == false))
	{
		// free(&game);
	}
	// valid path yum collectiv und ziel
	// flood fill zum pruefen 
	
	// validate_path(&game, y_max, x_max);
}
