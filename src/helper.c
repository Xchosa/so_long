/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:20:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/07 10:25:33 by poverbec         ###   ########.fr       */
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
// lvl2.ber
// strlen = 8 

void	check_input(int argc, char **argv)
{
	size_t filename;
	if (argc != 2 )
	{
		ft_putendl_fd("error\nInvalid number of arguments", STDERR_FILENO);
		exit(1);
	}
	filename = ft_strlen(argv[1]) -4;
	if (ft_strncmp(".ber", argv[1] + filename, 4) != 0)
	{
		ft_putendl_fd("error/n Not a '.ber' file given", STDERR_FILENO);
		exit(1);
	}
	
}



