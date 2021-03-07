/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:00:40 by vping             #+#    #+#             */
/*   Updated: 2021/03/02 22:00:41 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** get_floor: получить floor с проверкой.
*/

void	get_floor(char *tmp, t_all *cub)
{
	if (ft_isdigit(*tmp))
		cub->p.floore_r = ft_atoi(tmp);
	else
		error("Error\nNot set floore_r", cub);
	tmp += ft_digitlen(cub->p.floore_r) + 1;
	if (ft_isdigit(*tmp))
		cub->p.floore_g = ft_atoi(tmp);
	else
		error("Error\nNot set floore_g", cub);
	tmp += ft_digitlen(cub->p.floore_g) + 1;
	if (ft_isdigit(*tmp))
		cub->p.floore_b = ft_atoi(tmp);
	else
		error("Error\nNot set floore_b", cub);
}

/*
** get_ceiling: получить ceiling с проверкой.
*/

void	get_ceiling(char *tmp, t_all *cub)
{
	if (ft_isdigit(*tmp))
		cub->p.ceilling_r = ft_atoi(tmp);
	else
		error("Error\nNot set ceilling_r", cub);
	tmp += ft_digitlen(cub->p.ceilling_r) + 1;
	if (ft_isdigit(*tmp))
		cub->p.ceilling_g = ft_atoi(tmp);
	else
		error("Error\nNot set ceilling_g", cub);
	tmp += ft_digitlen(cub->p.ceilling_g) + 1;
	if (ft_isdigit(*tmp))
		cub->p.ceilling_b = ft_atoi(tmp);
	else
		error("Error\nNot set ceilling_b", cub);
}
