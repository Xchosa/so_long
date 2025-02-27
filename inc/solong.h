/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:42 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/27 16:42:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include <limits.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/wait.h>
# include <math.h>
# include <pthread.h>
#include "../mlx/include/MLX42/MLX42.h"

# define Pixel 32

// # ifndef WIDTH
// # 	define WIDTH 1
// # endif

// # ifndef HEIGHT
// # 	define HEIGHT 16
// # endif

# define PLAYER 'P'
# define WALL '1'
# define BACKGROUND '0'
# define EXIT 'E'
# define START 'P'
# define COLLECTIBLES 'C'

# define PNG_WALL "./img/brick_32.png"
# define PNG_BACKGROUND "./img/background.png"
# define PNG_EXIT "./img/goal.png"
# define PNG_PLAYER "./img/spirit.png"
# define PNG_COLLECTIVES "./img/collectives.png"





typedef struct s_game
{
	mlx_t	*mlx;
	char	**map;
	int		x;
	int		y;
}	t_game;

void	print_split(char **str);
void	ft_free_split(char **str);
int		check_input(int argc);
void 	get_map(char *map_name, t_game *game);

void	ft_escape_key(mlx_key_data_t keydata, void* param);

#endif