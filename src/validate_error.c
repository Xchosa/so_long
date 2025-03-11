/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:39:34 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/11 17:04:36 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

void	validate_error_map(char *error_msg, t_game *game)
{
	ft_free_split(game->copy_map);
	free_map(game);
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(1);
}

void	free_images(t_game *game, t_img *images)
{
	mlx_delete_image(game->mlx, images->background);
	mlx_delete_image(game->mlx, images->wall);
	mlx_delete_image(game->mlx, images->spirit);
	mlx_delete_image(game->mlx, images->collectives);
	mlx_delete_image(game->mlx, images->exit);
	mlx_delete_image(game->mlx, images->win);
	mlx_delete_image(game->mlx, images->loose);
	mlx_delete_image(game->mlx, images->droide);
	free(images);
}


void	gnl_exit(char *error_msg, int fd)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	close(fd);
	exit(1);
}

void	faild_split(char *error_msg, t_game *game)
{
	if (!game->copy_map)
		free_map_copy(game);
	if (!game->map)
		free_map(game);
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(1);
}
