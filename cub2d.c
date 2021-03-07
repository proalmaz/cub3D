/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:52:49 by vping             #+#    #+#             */
/*   Updated: 2021/03/02 21:53:45 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** print_map: печать карты с игроком.
*/

static	void	print_map(t_all *cub)
{
	int	i;
	int	j;

	i = -1;
	cub->point.y = 0;
	cub->data.img = mlx_new_image(cub->mlx, cub->p.res_w, cub->p.res_l);
	cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel,
			&cub->data.line_length, &cub->data.endian);
	while (++i != cub->p.size_map)
	{
		j = -1;
		cub->point.x = 0;
		while (cub->p.map[i][++j] != '\0')
		{
			if (cub->p.map[i][j] == '1')
				print_step(cub, 0x00FFFFFF);
			else if (i == cub->p.playr_y && j == cub->p.playr_x)
				print_step(cub, 0x006300FD);
			else if (cub->p.map[i][j] == '*' || cub->p.map[i][j] == '0')
				print_step(cub, 0x006300FD);
			cub->point.x += SCALE;
		}
		cub->point.y += SCALE;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->data.img, 50, 50);
}

/*
** key_hook: взаимодействие с клавиатурой.
*/

static	int		key_hook(int keycode, t_all *cub)
{
	mlx_destroy_image(cub->mlx, cub->data.img);
	if (keycode == 13)
	{
		cub->plr.x += cos(cub->plr.dir);
		cub->plr.y += sin(cub->plr.dir);
	}
	if (keycode == 1)
	{
		cub->plr.x -= cos(cub->plr.dir);
		cub->plr.y -= sin(cub->plr.dir);
	}
	if (keycode == 123)
		cub->plr.dir -= 0.1;
	if (keycode == 124)
		cub->plr.dir += 0.1;
	if (keycode == 53)
		close_win(cub);
	print_map(cub);
	print_player_cub(cub);
	print_player_pix(cub);
	print_ray(cub);
	print_rays(cub);
	return (0);
}

/*
** start_cub2d: запуск окна, работа в 2D.
*/

void			cub2d(t_all *cub)
{
	cub->plr.y = cub->p.playr_y * SCALE;
	cub->plr.x = cub->p.playr_x * SCALE;
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, cub->p.res_w,
			cub->p.res_l, "cub2D");
	print_map(cub);
	print_player_cub(cub);
	print_player_pix(cub);
	print_ray(cub);
	print_rays(cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, key_hook, cub);
	mlx_hook(cub->mlx_win, 17, 1L << 0, close_win, cub);
	mlx_loop(cub->mlx);
}
