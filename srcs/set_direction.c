/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:02:05 by vping             #+#    #+#             */
/*   Updated: 2021/03/02 22:02:45 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		set_dir_n_w(t_all *data)
{
	if (data->plr.dir_symbol == 'N')
	{
		data->plr.dir_y = -1;
		data->plr.dir_x = 0;
		data->plr.plane_x = 0.66;
		data->plr.plane_y = 0;
	}
	else if (data->plr.dir_symbol == 'W')
	{
		data->plr.dir_y = 0;
		data->plr.dir_x = -1;
		data->plr.plane_x = 0;
		data->plr.plane_y = -0.66;
	}
}

void			set_dir_plr(t_all *data)
{
	if (data->plr.dir_symbol == 'E')
	{
		data->plr.dir_y = 0;
		data->plr.dir_x = 1;
		data->plr.plane_x = 0;
		data->plr.plane_y = 0.66;
	}
	else if (data->plr.dir_symbol == 'S')
	{
		data->plr.dir_y = 1;
		data->plr.dir_x = 0;
		data->plr.plane_x = -0.66;
		data->plr.plane_y = 0;
	}
	else
		set_dir_n_w(data);
}
