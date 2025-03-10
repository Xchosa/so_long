/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:33:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/10 13:35:29 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void find_position_player(t_game *game)
{
	int y = 0;
	int x;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if(game->map[y][x] == 'P')
			{
				game->player_yx[0] = y;
				game->player_yx[1] = x;
				return;
			}
			x++;
		}
		y++;
	}
	exit(ft_printf("error\n could not find Starting Point of Player"));
}

bool exit_unlocked(t_game *game)
{
	bool	exit_unlocked;
	exit_unlocked = false;
	if (game->collectables == 0)
		exit_unlocked = true;
	return (exit_unlocked);
}

bool	validate_edge(t_game *game, int x_max, int y_max)
{
	int x;
	int y;
	x = 0;
	y = 0;
	bool bool_edges;
	bool_edges = true;
	while(y < y_max)
	{
		if((game->map[y][0] != '1') || (game->map[y][x_max-1]) != '1')
		{
			return(bool_edges = false);
		}
		y++;
	}
	while(x < x_max )
	{
		if(((game->map[0][x]) != '1') || (game->map[y_max-1][x] != '1'))
		{
			return(bool_edges = false);
		}
		x++;
	}
	return(bool_edges);
}



// validate_rectangular, and if map is surrounded by walls
bool	validate_rectangular(t_game *game, int y_max )
{
	bool bool_rectangular;
	bool_rectangular = true;
	int y = 0;
	int current_row_length;
	int first_row_length= ft_strlen(game->map[0]);
	while(y < y_max)
	{
		current_row_length = ft_strlen(game->map[y]);
		if (current_row_length !=  first_row_length)
		{
			return(bool_rectangular = false);
		}
		y++;
	}
	return (bool_rectangular);
}


void validate_map(t_game *game)
{
	int x_max;
	int y_max;
	x_max = game->x;
	y_max = game->y;
	game->x = 0;
	game->y = 0;
	find_position_player(game);
	game->moves_nbr = 0;
	if ((validate_edge(game, x_max, y_max) == false))
		validate_error_map("Map is not surrounded by walls", game);
	if (validate_rectangular(game, y_max) == false)
		validate_error_map("Map is not rectangular", game);
	validate_path(game);
	game->x = x_max;
	game->y = y_max;
	game->moves_nbr = 0;
	game->exit_unlocked = exit_unlocked(game);
	game->collectables = 0;
	game->finished = false;
}
