/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:52:59 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/13 14:45:13 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	validate_characters_general(char *joined_line, int fd)
{
	int	i;

	i = 0;
	while (joined_line[i] != '\0')
	{
		if (joined_line[i] != '0' && joined_line[i] != '1'
			&& joined_line[i] != 'P' && joined_line[i] != 'E'
			&& joined_line[i] != 'C' && joined_line[i] != '\n')
		{
			ft_printf ("Map with wrong input: %c\n", joined_line[i]);
			free (joined_line);
			close(fd);
			exit(1);
		}
		i++;
	}
	count_player(joined_line, fd);
	return ;
}

void	count_player(char *map_as_string, int fd)
{
	int	count_player;
	int	i;

	i = 0;
	count_player = 0;
	while (map_as_string[i] != '\0')
	{
		if (map_as_string[i] == 'P')
			count_player++;
		i++;
	}
	if (count_player == 0)
	{
		free(map_as_string);
		close(fd);
		exit(ft_printf("Error \nNo player found"));
	}
	if (count_player == 2)
	{
		free(map_as_string);
		close(fd);
		exit(ft_printf("Error \n%d player found", count_player));
	}
}

int	count_collectables(char *game_as_string, t_game *game)
{
	int	count_collectables;
	int	i;

	i = 0;
	count_collectables = 0;
	while (game_as_string[i])
	{
		if (game_as_string[i] == 'C')
			count_collectables++;
		i++;
	}
	if (count_collectables == 0)
	{
		validate_error_map("No collectiables found", game);
	}
	return (count_collectables);
}
