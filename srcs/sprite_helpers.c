/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:02:58 by vping             #+#    #+#             */
/*   Updated: 2021/03/02 22:03:00 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** save_position_sprites: сохранить позицию спрайтов
** и вернуть их количество.
*/

void			save_position_sprites(t_all *cub)
{
	int i;
	int j;
	int coll;

	i = 0;
	coll = 0;
	while (cub->p.map[i] != NULL)
	{
		j = 0;
		while (cub->p.map[i][j] != '\0')
		{
			if (cub->p.map[i][j] == 'B')
			{
				cub->x[coll] = j + 0.5;
				cub->y[coll] = i + 0.5;
				coll++;
			}
			++j;
		}
		++i;
	}
}

/*
** counting_sprites: подсчет спрайтов.
*/

int				counting_sprites(t_all *cub)
{
	int i;
	int j;
	int coll;

	i = 0;
	coll = 0;
	while (cub->p.map[i] != NULL)
	{
		j = 0;
		while (cub->p.map[i][j] != '\0')
		{
			if (cub->p.map[i][j] == 'B')
				coll++;
			++j;
		}
		++i;
	}
	return (coll);
}

/*
** swap_sprite: переместить местами спрайты.
*/

static	void	swap_sprite(t_all *cub, int *j)
{
	float tmp;

	tmp = cub->dist[*j - 1];
	cub->dist[*j - 1] = cub->dist[*j];
	cub->dist[*j] = tmp;
	tmp = cub->x[*j - 1];
	cub->x[*j - 1] = cub->x[*j];
	cub->x[*j] = tmp;
	tmp = cub->y[*j - 1];
	cub->y[*j - 1] = cub->y[*j];
	cub->y[*j] = tmp;
}

/*
** bubble_sort: сортировка метод "пузырька".
*/

static	void	bubble_sort(t_all *cub)
{
	int i;
	int j;

	i = 1;
	while (i < cub->p.coll_sprite)
	{
		j = i;
		while ((int)cub->dist[j] > (int)cub->dist[j - 1] && j != 0)
		{
			swap_sprite(cub, &j);
			--j;
		}
		++i;
	}
}

/*
** sort_sprite: сортировка спрайтов.
*/

void			sort_sprite(t_all *cub)
{
	int i;

	i = -1;
	while (++i < cub->p.coll_sprite)
	{
		cub->dist[i] = ((cub->plr.x - cub->x[i])
						* (cub->plr.x - cub->x[i])
						+ (cub->plr.y - cub->y[i]) * (cub->plr.y - cub->y[i]));
	}
	if (cub->p.coll_sprite > 1)
		bubble_sort(cub);
}
