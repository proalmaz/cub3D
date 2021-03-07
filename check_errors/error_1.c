/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:32:05 by vping             #+#    #+#             */
/*   Updated: 2021/02/23 17:32:07 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** check_errors_arg: проверка входных данных на ошибки.
*/

void			check_errors_arg(int ac, char **av, t_all *cub)
{
	if (ac == 2 || ac == 3)
	{
		if (ac == 2)
		{
			if (check_av_map(av[1]))
				error("Error\nMap's name is not 'map.cub'", cub);
		}
		else if (ac == 3)
		{
			if (ft_strlen(av[2]) != 6 || check_av_save(av[2]))
				error("Error\n3 the argument is not '--save'", cub);
		}
	}
	else if (ac != 2 && ac != 3)
		error("Error\nThe number of arguments is not 2 or 3", cub);
}

/*
** check_tab: проверка на пробелы в конце строки.
*/

void			check_tab(char *line, t_all *cub)
{
	if (line[ft_strlen(line) - 1] == ' ')
		error("Error\nA space was found after the indexer", cub);
}

/*
** all_tab_in_line: проверка, состоит ли строка только из пробелов.
*/

void			all_tab_in_line(char *str, t_all *cub)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return ;
		++i;
	}
	ft_putstr_fd("Error\nThere is an empty line ", 1);
	error("with spaces at the end of the map", cub);
}

/*
** check_symbols_map_norm: функция для нормы.
*/

static	void	check_symbols_map_norm(int *flag, int *i, int *j, t_all *cub)
{
	if (cub->p.map[*i][*j] == 'N' || cub->p.map[*i][*j] == 'S'
		|| cub->p.map[*i][*j] == 'E' || cub->p.map[*i][*j] == 'W')
	{
		if (*flag == 0)
		{
			*flag = 1;
			cub->p.playr = &cub->p.map[*i][*j];
			cub->p.playr_y = *i;
			cub->p.playr_x = *j;
		}
		else
			error("Error\nThe player meets more than 1 time", cub);
	}
}

/*
** check_symbols_map: проверка символов карты.
*/

void			check_symbols_map(int size, t_all *cub)
{
	int i;
	int j;
	int flag;

	i = -1;
	flag = 0;
	while (++i != size)
	{
		j = 0;
		while (cub->p.map[i][j] != '\0')
		{
			check_symbols_map_norm(&flag, &i, &j, cub);
			if (cub->p.map[i][j] == ' ' || cub->p.map[i][j] == '0'
				|| cub->p.map[i][j] == '1' || cub->p.map[i][j] == '2'
				|| cub->p.map[i][j] == 'N' || cub->p.map[i][j] == 'S'
				|| cub->p.map[i][j] == 'E' || cub->p.map[i][j] == 'W')
				++j;
			else
				error("Error\nWrong symbol in the map", cub);
		}
	}
	if (flag == 0)
		error("Error\nThe player never meets", cub);
}
