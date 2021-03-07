/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:52:04 by vping             #+#    #+#             */
/*   Updated: 2021/03/04 18:52:48 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "libraries/libft/libft.h"
# include "libraries/minilibx_mms/mlx.h"
# include <math.h>
# include <fcntl.h>

# define SCALE 16
# define PI 3.14159265359
# define TEXWIDTH 64
# define TEXHEIGHT 64

/*
** t_parser: структура парсера.
*/

typedef	struct		s_parser
{
	int				res_w;
	int				res_l;

	char			*nor_tex;
	char			*sou_tex;
	char			*wes_tex;
	char			*eas_tex;

	char			*spr_tex;

	int				floore_r;
	int				floore_g;
	int				floore_b;
	int				floore_flag;

	int				ceilling_r;
	int				ceilling_g;
	int				ceilling_b;
	int				ceilling_flag;

	char			**map;

	char			*playr;
	int				playr_x;
	int				playr_y;

	int				size_map;

	int				coll_sprite;
}					t_parser;

/*
** t_point_print: структура печати карты.
*/

typedef struct		s_point_print
{
	double			x;
	double			y;
}					t_point_print;

/*
** t_plr: структура игрока.
*/

typedef struct		s_plr
{
	double			x;
	double			y;
	double			dir;
	char			dir_symbol;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			start;
	double			end;
}					t_plr;

/*
** t_data: структура данных mlx.
*/

typedef	struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

/*
** t_norm_print_sprite: структура для нормы.
*/

typedef struct		s_norm_print_sprite
{
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				d;
	int				tex_y;
	int				color;
}					t_norm_print_sprite;

/*
** t_norm_print_map: структура для нормы.
*/

typedef struct		s_norm_print_map
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
}					t_norm_print_map;

/*
** t_all: структура в которой находится все.
*/

typedef struct		s_all
{
	void			*mlx;
	void			*mlx_win;
	t_parser		p;
	t_data			t_n;
	t_data			t_s;
	t_data			t_w;
	t_data			t_e;
	t_data			t_spr;
	t_data			data;
	t_point_print	point;
	t_plr			plr;
	float			*x;
	float			*y;
	float			*dist;
	double			*close_sprite;
}					t_all;

void				check_errors_arg(int ac, char **av, t_all *cub);

void				parser(char **av, t_all *data);

void				parser_map(int fd, t_all *cub);

void				check_all_data(t_all *cub);

void				check_tab_in_r_f(char *line, t_all *cub);

void				check_tab(char *line, t_all *cub);

void				check_c(t_all *cub);

void				check_f(t_all *cub);

void				check_r(t_all *cub);

void				all_tab_in_line(char *str, t_all *cub);

void				check_symbols_map(int size, t_all *cub);

void				get_floor(char *tmp, t_all *cub);

void				get_ceiling(char *tmp, t_all *cub);

void				cub2d(t_all *cub);

void				start_cub3d(t_all *cub, int argc);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);

void				error(char *str, t_all *cub);

void				move_up(t_all *cub, double s);

void				move_back(t_all *cub, double s);

void				move_left(t_all *cub, double s);

void				move_right(t_all *cub, double s);

void				turn_right(t_all *cub, double r);

void				turn_left(t_all *cub, double r);

void				get_sprite(t_all *cub);

void				set_dir_plr(t_all *cub);

void				sort_sprite(t_all *cub);

void				save_position_sprites(t_all *cub);

void				screenshot(t_all *cub);

void				free_lst_map(t_list **lst);

void				print_step(t_all *cub, int color);

void				print_ray(t_all *cub);

void				print_rays(t_all *cub);

void				print_player_pix(t_all *cub);

void				print_player_cub(t_all *cub);

void				set_cam_ray_mapxy(t_norm_print_map *n, int *x, t_all *cub);

void				calc_step_start(t_norm_print_map *n, t_all *cub);

void				check_hit(t_norm_print_map *n, t_all *cub);

void				calc_more(t_norm_print_map *n, t_all *cub, int *x);

void				side_world(t_norm_print_map *n, t_all *cub, int *x, int *y);

void				side_world_norm(t_norm_print_map *n, t_all *cub,
									int *x, int *y);

void				print_sprite_norm(t_all *cub, t_norm_print_sprite *s,
		int *y, int *stripe);

void				set_sprite(t_all *cub, t_norm_print_sprite *s, int *i);

int					close_win(t_all *cub);

int					counting_sprites(t_all *cub);

int					create_rgb(int r, int g, int b);

int					check_av_map(char *av);

int					check_av_save(char *av);

unsigned int		get_pixel(t_data *data, int x, int y);

#endif
