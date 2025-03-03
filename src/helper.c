/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:20:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/03 10:33:56 by poverbec         ###   ########.fr       */
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

