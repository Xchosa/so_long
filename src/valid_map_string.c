/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:52:59 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/10 14:06:34 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/solong.h"
#include "../mlx/include/MLX42/MLX42.h"


void validate_characters_general(char *joined_line)
{
	int i;
	i = 0;
	while (joined_line[i] != '\0')
    {
        if (joined_line[i] != '0' && joined_line[i] != '1' &&
            joined_line[i] != 'P' && joined_line[i] != 'E' &&
            joined_line[i] != 'C' && joined_line[i] != '\n')
        	{
				free(joined_line);
           		exit(ft_printf("Map with wrong input: %s", joined_line[i])); 
        	}
        i++;
    }
	count_player(joined_line);
}

void count_player(char *map_as_string)
{
	int count_player;
	int i;
	i = 0;
	count_player = 0;
	while (map_as_string[i] != '\0')
	{
		if (map_as_string[i] == 'P')
			count_player++;
		i++;
	}
	if (count_player == 0 )
	{
		free(map_as_string);
		exit(ft_printf("error/n No player found"));
	}
	if (count_player == 2 )
	{
		free(map_as_string);
		exit(ft_printf("error/n %d player found", count_player));
	}
}
int count_collectables(char *game_as_string)
{
	int count_collectables;
	int i;
	i = 0;
	count_collectables = 0;
	while (game_as_string[i])
	{
		if (game_as_string[i] == 'C')
			count_collectables++;
		i++;
	}
	if (count_collectables == 0)
		ft_printf("error\n No collectiables found");
	return(count_collectables);
}