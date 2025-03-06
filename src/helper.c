/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:20:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/06 10:45:40 by poverbec         ###   ########.fr       */
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



