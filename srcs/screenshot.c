/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:01:16 by vping             #+#    #+#             */
/*   Updated: 2021/03/02 22:01:55 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			turn_left(t_all *cub, double r)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = cub->plr.dir_y;
	old_plane_x = cub->plr.plane_y;
	cub->plr.dir_y = cub->plr.dir_y * cos(r) - cub->plr.dir_x * sin(r);
	cub->plr.dir_x = old_dir_x * sin(r) + cub->plr.dir_x * cos(r);
	cub->plr.plane_y = cub->plr.plane_y * cos(r) - cub->plr.plane_x * sin(r);
	cub->plr.plane_x = old_plane_x * sin(r) + cub->plr.plane_x * cos(r);
}

static	void	fill_screen(int fd, t_all *cub)
{
	int i;
	int j;
	int color;

	i = cub->p.res_l;
	while (--i >= 0)
	{
		j = -1;
		while (++j < cub->p.res_w)
		{
			color = get_pixel(&cub->data, j, i);
			write(fd, &color, 4);
		}
	}
	exit(0);
}

static	void	screenshot_norm_two(int fd, int all_pix, int zero, int size)
{
	write(fd, &zero, 4);
	write(fd, &size, 4);
	all_pix = 1000;
	write(fd, &all_pix, 4);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
}

static	void	screenshot_norm_one(int fd)
{
	short	plane;

	plane = 1;
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

/*
** screenshot: сделать скриншот.
*/

void			screenshot(t_all *cub)
{
	int		fd;
	int		all_pix;
	int		zero;
	int		pos_pix;
	int		size;

	fd = open("screen.bmp", O_CREAT | O_RDWR, 0666);
	all_pix = cub->p.res_w * cub->p.res_l * 4 + 54;
	zero = 0;
	pos_pix = 54;
	size = cub->p.res_w * cub->p.res_l;
	write(fd, "BM", 2);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pix, 4);
	pos_pix = 40;
	write(fd, &pos_pix, 4);
	write(fd, &cub->p.res_w, 4);
	write(fd, &cub->p.res_l, 4);
	screenshot_norm_one(fd);
	screenshot_norm_two(fd, all_pix, zero, size);
	fill_screen(fd, cub);
}
