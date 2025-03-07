/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:39:34 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/07 10:58:38 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"


void validate_error_map(char *error_msg, t_game *game)
{
	// ft_free_split(game.copy_map);
	// ft_free_split(game.map);
	// free of player_start ? 
	(void)game;
	ft_putendl_fd("error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(1);
	
}


