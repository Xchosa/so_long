/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:42 by poverbec          #+#    #+#             */
/*   Updated: 2025/03/11 16:54:09 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

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
# include <stdarg.h> 
# include "../mlx/include/MLX42/MLX42.h"

# define PIXEL 32

// 			Define Assets of the input map
# define PLAYER 'P'
# define WALL '1'
# define BACKGROUND '0'
# define EXIT 'E'
# define START 'P'
# define COLLECTIBLES 'C'
# define DROIDE 'D'

// 			Define Path to pictures in png format 
# define GAME_NAME	"STAR WARS"
# define WIN	"./img/be_the_force_with_you"
# define LOOSE	"./img/Loose.png"
# define PNG_WALL "./img/star_space.png"
# define PNG_BACKGROUND "./img/background_star.png"
# define PNG_EXIT "./img/ship.png"
# define PNG_PLAYER "./img/yoda.png"
# define PNG_COLLECTIVES "./img/R2_D2.png"
# define PNG_DROIDE "./img/Droide.png"

typedef struct s_texture
{
	mlx_texture_t	*background;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectives;
	mlx_texture_t	*spirit;
	mlx_texture_t	*exit;
	mlx_texture_t	*loose;
	mlx_texture_t	*win;
	mlx_texture_t	*droide;
}	t_texture;

typedef struct s_img
{
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*collectives;
	mlx_image_t	*spirit;
	mlx_image_t	*exit;
	mlx_image_t	*loose;
	mlx_image_t	*win;
	mlx_image_t	*droide;
}	t_img;

typedef struct s_game
{
	mlx_t		*mlx;
	t_img		*image;
	char		**map;
	char		**copy_map;
	int			x;
	int			y;
	int			player_yx[2];
	int			collectables;
	int			collectables_check;
	bool		map_exit;
	bool		exit_unlocked;
	int			moves_nbr;
	bool		finished;
}	t_game;

void	check_input(int argc, char **argv);
void	get_map(char *map_name, t_game *game);
void	leaks(void);
void	validate_map(t_game *game);
bool	validate_edge(t_game *game, int x_max, int y_max);
bool	validate_rectangular(t_game *game, int y_max);
void	validate_characters_general(char *joined_line);
bool	exit_unlocked(t_game *game);
void	count_player(char *map_as_string);
int		count_collectables(char *game_as_string, t_game *game);
void	find_position_player(t_game *game);

// check if Exit is reachable 
void	validate_path(t_game *game);
void	fill_texture_image(t_texture *texture, t_game *game);
void	ft_image_to_window(int y, int x, t_game *game);
void	put_images(t_texture *texture, t_game *game);
void	flood_fill(t_game *game, int y, int x);

void	render_map(t_game *game, t_texture *texture);
// move player
void	ft_escape_key(mlx_key_data_t keydata, void *param);
void	move_player_y_x(int y, int x, t_game *game, t_img *image);
void	set_image_player(t_game *game, t_img *image, int new_x, int new_y);
void	set_player_nbr_moves(t_game *game, int new_x, int new_y);
void	print_success(int new_x, int new_y, t_game *game, t_img *image);

// Handle Game End
void	terminate_game(t_game *game, t_img *images);
void	free_map_copy(t_game *game);
void	validate_error_map(char *error_msg, t_game *game);
void	free_images(t_game *game, t_img *images);
void	free_map(t_game *game);
void	ft_free_split(char **str);
void	faild_split(char *error_msg, t_game *game);
void	gnl_exit(char *error_msg, int fd);

//bonus Droide is petroling
void	bonus_droide(t_game *game);
void	print_loose(t_game *game, t_img *image);

#endif