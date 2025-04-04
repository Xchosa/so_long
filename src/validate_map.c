/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:33:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/17 13:17:24 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	find_position_player(t_game	*game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_yx[0] = y;
				game->player_yx[1] = x;
				return ;
			}
			x++;
		}
		y++;
	}
	validate_error_map("could not find Starting Point of Player", game);
}

bool	exit_unlocked(t_game *game)
{
	bool	exit_unlocked;

	exit_unlocked = false;
	if (game->collectables == 0)
		exit_unlocked = true;
	return (exit_unlocked);
}

bool	validate_edge(t_game *game, int x_max, int y_max)
{
	int		x;
	int		y;
	bool	bool_edges;

	x = 0;
	y = 0;
	bool_edges = true;
	while (y < y_max)
	{
		if ((game->map[y][0] != '1') || (game->map[y][x_max - 1]) != '1')
		{
			return (bool_edges = false);
		}
		y++;
	}
	while (x < x_max)
	{
		if (((game->map[0][x]) != '1') || (game->map[y_max - 1][x] != '1'))
		{
			return (bool_edges = false);
		}
		x++;
	}
	return (bool_edges);
}

// validate_rectangular, and if map is surrounded by walls
bool	validate_rectangular(t_game *game, int y_max )
{
	bool		bool_rectangular;
	int			y;
	size_t		first_row_length;

	bool_rectangular = true;
	y = 0;
	first_row_length = ft_strlen(game->map[0]);
	while (y < y_max)
	{
		if (game->map[y] == NULL || (ft_strlen(game->map[y]))
			!= first_row_length)
		{
			return (bool_rectangular = false);
		}
		y++;
	}
	return (bool_rectangular);
}

void	validate_map(t_game *game)
{
	int	x_max;
	int	y_max;

	x_max = game->x;
	y_max = game->y;
	game->x = 0;
	game->y = 0;
	find_position_player(game);
	game->moves_nbr = 0;
	if (validate_rectangular(game, y_max) == false)
		validate_error_map("Map is not rectangular", game);
	if ((validate_edge(game, x_max, y_max) == false))
		validate_error_map("Map is not surrounded by walls", game);
	validate_path(game);
	game->x = x_max;
	game->y = y_max;
	game->moves_nbr = 0;
	game->exit_unlocked = exit_unlocked(game);
	game->collectables = 0;
	game->finished = false;
}
