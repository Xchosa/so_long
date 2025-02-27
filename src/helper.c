/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:20:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/27 15:36:27 by poverbec         ###   ########.fr       */
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
	else
		return(EXIT_SUCCESS);
}

void	get_map(char *map_name, t_game *game)
{
	int fd;
	char *map_line;
	char *joined_line;
	joined_line = "";
	
	
	game->y = 1;
	fd = open(map_name, O_RDONLY );
	if(!fd)
		exit(EXIT_FAILURE);
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		joined_line = ft_strjoin(joined_line, map_line);
		free(map_line);
		map_line = get_next_line(fd);
		game->y++;
		
	}
	game->map = ft_split(joined_line, '\n');
	
	ft_printf("%s\n",joined_line);
	game->x = ft_strlen(game->map[0]);
	free(joined_line);
	// print_split(game->map);
}



void	ft_escape_key(mlx_key_data_t keydata, void* param)
{
	
	// param - das bild was jedes mal neu reingegeben wird 
	(void) param;
	// if(keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	// 	fractol->img->width += 5;
	// if(keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
	// 	fractol->img->height + 5;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit(1);
	}
}