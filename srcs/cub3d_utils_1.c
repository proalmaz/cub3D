/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:56:47 by vping             #+#    #+#             */
/*   Updated: 2021/03/02 21:56:48 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** close_win: закрытие окна и выход из программы.
*/

int					close_win(t_all *cub)
{
	mlx_destroy_window(cub->mlx, cub->mlx_win);
	system("killall afplay");
	exit(0);
	return (0);
}

/*
** create_rgb: преобразование RGB в hex.
*/

int					create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/*
** free_lst_map: очистить лист с картой.
*/

void				free_lst_map(t_list **lst)
{
	t_list *p;

	while (*lst)
	{
		p = (*lst)->next;
		free(*lst);
		*lst = p;
	}
	*lst = NULL;
}

/*
** get_pixel: берет пиксель из текстуры.
*/

unsigned	int		get_pixel(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

/*
** my_mlx_pixel_put: измененная функция mlx_pixel_put
** для увеличения скорости работы.
*/

void				my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
