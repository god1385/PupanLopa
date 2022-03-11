/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:10:38 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/10 21:33:56 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../get_next_line.h"

# ifndef IMAGE
#  define IMAGE 50
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

enum e_keycode
{
	RIGHT = 2,
	UP = 13,
	LEFT = 0,
	DOWN = 1,
	END = 53
};

typedef enum e_tiles
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
}	t_tiles;

typedef struct s_vector
{
	int		x;
	int		y;
}				t_vector;

typedef struct s_tilestruct
{
	t_vector			position;
	t_tiles				type;
	struct s_tilestruct	*up;
	struct s_tilestruct	*down;
	struct s_tilestruct	*left;
	struct s_tilestruct	*right;
}	t_tilestruct;

typedef struct s_map
{
	t_vector	size;
	t_vector	position;
	int			player;
	int			exit;
	int			collectable;
}				t_map;

typedef struct s_enemy
{
	t_tilestruct	*tile;
	int				framecount;
	int				action_frames;
	void			*action_img;
}	t_enemy;

typedef struct s_player
{
	t_tilestruct	*tile;
	void			*current_img;
	int				framecount;
	int				idle_frames;
	void			*idle_img_0;
	void			*idle_img_1;
	int				action_frames;
	struct s_player	*next;
	void			*action_img;
}	t_player;

typedef struct s_data
{
	void			*img;
	void			*mlx;
	void			*win;
	t_vector		window_size;
	char			*address;
	int				bits_pixels;
	int				line_length;
	int				endian;
	t_player		player;
	t_player		*enemy;
	int				collectables;
	void			*wallimg;
	void			*playerimg;
	void			*exitfinishimg;
	void			*collectableimg;
	void			*player_sit;
	void			*emptyimg;
	void			*exitimg;
	void			*player_midd;
	void			*enemy_stand;
	void			*enemy_half;
	void			*enenemy_sit;
	int				moves;
	int				enemy_count;
	t_tilestruct	**tiles;
}				t_data;

char			**map_reader(char *file);
int				ycounter(char **map);
int				ft_strlen(const char *str);
t_tilestruct	**tilesinitialise(char **map, t_data	*data);
void			drawwallandempty(t_data *data);
int				validation(char **map, t_data *dat);
void			generation(t_data data);
void			ft_free_chartable(char **map);
int				end(t_data *data);
int				input(int key, t_data *data);
int				enemy(t_data *data);
void			spawn_enemy(t_tilestruct *tile, t_data *data);
void			exit_program(char *str);
int				checker_char(char map);
int				check_borders(char c, t_vector position, t_vector size);
void			drawenemy(t_data *data);
int				imagestand(t_data data, t_vector position, int frame);
int				imagemid(t_data data, t_vector position, int frame);
int				enemystand(t_data data, t_vector position, int frame);
int				enemyhalf(t_data data, t_vector position, int frame);
int				end(t_data *data);

#endif