/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:20:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/28 16:44:37 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"


void ft_free_split(char **str)
{
	int i;
	i = 0;
	while(*str[i])
	{
		free(str[i]);
		i++;
	}
}

void print_split(char **str)
{
	ft_printf("%s", str[0]);
	// int i;
	// i = 0;
	// while(str[i])
	// {
	// 	ftprintf("%s\n", str[i]);
	// 	i++;
	// }
}

int check_input(int argc)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	// .ber datei
	else
		return(EXIT_SUCCESS);
}

int	validate_map(t_game game)
{
	int x;
	int y;
	int x_max = game.x; // max value 
	int y_max = game.y; // 
	x = 0;
	y = 0;
	while(y <= y_max )
	{
		if(((game.map[0][y]) != '1') || (game.map[x_max][y] != '1'))
			return(ft_printf("error map wall"));
		y++;
	}
	while(x <= x_max )
	{
		if(((game.map[x][0]) != '1') || (game.map[x][y_max] != '1'))
			return(ft_printf("error map wall"));
	}
	printf("map value %s", game.map[x][y]);
	if((game.x != '1') || (game.y != '1'))
		return(printf("not 1"));
	printf("x value %d", game.x);// x is max value 
	printf("y value %d", game.y);

	
	// raender alle 1
	// mind 1 collectiv
	// ein exit 
	// rechteckig - jede zeile und spalte gleich lang 
	// valid path yum collectiv und ziel
	// flood fill zum pruefen 
}





void	ft_escape_key(mlx_key_data_t keydata, void *param)
{
	
	// param - das bild was jedes mal neu reingegeben wird 
	 (void) param;
	// // if(keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	// // 	fractol->img->width += 5;
	// if(keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		// image..img->height ;
	
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit(1);
	}
}

