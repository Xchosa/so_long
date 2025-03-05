/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:42 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/05 16:41:42 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
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

# define GAME_NAME	"STAR WARS"
# define WIN	"./img/be_the_force_with_you"
# define PNG_WALL "./img/star_space.png"
# define PNG_BACKGROUND "./img/background_star.png"
# define PNG_EXIT "./img/ship.png"
# define PNG_PLAYER "./img/yoda.png"
# define PNG_COLLECTIVES "./img/R2_D2.png"





typedef struct s_game
{
	mlx_t	*mlx;
	char	**map;
	char	**copy_map;
	int		x;
	int		y;
	int 	player_start[2];
	int		collectables;
	int		collectables_check;
	bool	map_exit;
}	t_game;

typedef struct s_texture
{
	mlx_texture_t *background;
	mlx_texture_t *wall;
	mlx_texture_t *collectives;
	mlx_texture_t *spirit;
	mlx_texture_t *exit;
	
}	t_texture;

typedef struct s_img
{
	mlx_image_t *background;
	mlx_image_t *wall;
	mlx_image_t *collectives;
	mlx_image_t *spirit;
	mlx_image_t *exit;
	
}	t_img;

void	print_split(char **str);
void	ft_free_split(char **str);
int		check_input(int argc);
void	validate_map(t_game game);
bool	validate_edge(t_game game, int x_max, int y_max);
bool	validate_rectangular(t_game game, int y_max);
void	validate_characters_general(char *joined_line);
void	validate_path(t_game *game, int y_max, int x_max);
void	count_player(char *map_as_string);
int		count_collectables(char *game_as_string);

void 	get_map(char *map_name, t_game *game);
void	fill_map(t_game *game, t_img *image, t_texture *texture);
void	fill_texture_image(t_texture *texture, t_img *image, t_game *game);
//void	fill_map(t_game *game);

void	ft_escape_key(mlx_key_data_t keydata, void* param);

#endif