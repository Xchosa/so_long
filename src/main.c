/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:18:41 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/10 09:32:20 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"

int main(int argc, char **argv)
{
	t_game	game;
	//t_img	image;
	t_texture	texture;
	
	check_input(argc, argv);

	// ft_printf("check seq \n");
	get_map(argv[1], &game);
	validate_map(&game);
	render_map(&game, &texture);
	ft_printf("%d  collectables collected from : %d collectables \n", game.collectables, game.collectables_check);
	ft_printf("Exit unlocked? %s", game.exit_unlocked);
	mlx_key_hook(game.mlx, &ft_escape_key, &game);
	
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx); //free everything left // mlx_delete_image(game->mlx, img);
	return(EXIT_SUCCESS);
}


// .berfile