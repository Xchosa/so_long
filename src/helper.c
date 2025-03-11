/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:20:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/11 15:45:29 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
}

void	free_map_copy(t_game *game)
{
	int	i;

	i = 0;
	while (game->copy_map[i])
	{
		free(game->copy_map[i]);
		i++;
	}
}

void	terminate_game(t_game *game, t_img *images)
{
	free_images(game, images);
	free_map(game);
	mlx_terminate(game->mlx);
	exit(1);
}

void	check_input(int argc, char **argv)
{
	size_t	filename;

	if (argc != 2)
	{
		ft_putendl_fd("error\nInvalid number of arguments", STDERR_FILENO);
		exit(1);
	}
	filename = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".ber", argv[1] + filename, 4) != 0)
	{
		ft_putendl_fd("error/n Not a '.ber' file given", STDERR_FILENO);
		exit(1);
	}
}
