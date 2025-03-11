/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:18:41 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/11 17:39:57 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_texture	texture;
	atexit(leaks);

	game.image = malloc(sizeof(t_img));
	check_input (argc, argv);
	get_map(argv[1], &game);
	validate_map(&game);
	render_map(&game, &texture);
	mlx_key_hook(game.mlx, &ft_escape_key, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
// free game->image if error 
// ft_join in const