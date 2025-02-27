/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:18:41 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/27 16:50:44 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"


void fill_map(t_game *game)
{
	int x;
	int y;
// sep func 

	game->mlx = mlx_init(Pixel * game->x, Pixel * game->y, "so_long",true);

	if (!game->mlx)
	{
		ft_printf("EMPTY");
		return ;
	}
	mlx_texture_t *png = mlx_load_png("./img/brick_32.png");
	if (!png)
	{
		ft_printf("ERROR\n");
		return ;
	}
	mlx_image_t *img = mlx_texture_to_image(game->mlx, png);
	mlx_delete_texture(png); 

	y = 0;
	x = 0;
	while (game->map[y]) // x noch \0 , darf nicht geprueft werde 
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALL)
			{
				mlx_image_to_window(game->mlx, img, x * Pixel, y * Pixel);
			}
			x++;
		}
		y++;
	}
	
	

}



int main(int argc, char **argv)
{
	t_game	game;
	
	check_input(argc);
	get_map(argv[1], &game);
	// validate_map() 
	fill_map(&game);

	mlx_key_hook(game.mlx, &ft_escape_key, &game);  
	//mlx_key_hook()
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx); //free everything left // mlx_delete_image(game->mlx, img);
	return(EXIT_SUCCESS);
}


// .berfile