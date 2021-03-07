/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:03:29 by vping             #+#    #+#             */
/*   Updated: 2021/03/02 22:06:15 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	parser_inf_norm(char *line, int id, int index, t_all *cub)
{
	char *tmp;

	tmp = &line[index];
	if (id == 6)
		cub->p.spr_tex = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 7)
	{
		check_tab_in_r_f(tmp, cub);
		get_floor(tmp, cub);
		check_f(cub);
	}
	else if (id == 8)
	{
		check_tab_in_r_f(tmp, cub);
		get_ceiling(tmp, cub);
		check_c(cub);
	}
}

/*
** parser_inf: парсинг информации в зависимости от индификаторов.
*/

static	void	parser_id(int index, char *line, int id, t_all *cub)
{
	char *tmp;

	while (line[index] == ' ' || line[index] == '\t')
		++index;
	tmp = &line[index];
	if (id == 1)
	{
		cub->p.res_w = ft_atoi(tmp);
		tmp += ft_digitlen(cub->p.res_w);
		cub->p.res_l = ft_atoi(tmp);
		check_r(cub);
	}
	else if (id == 2)
		cub->p.nor_tex = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 3)
		cub->p.sou_tex = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 4)
		cub->p.wes_tex = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 5)
		cub->p.eas_tex = ft_substr(line, index, ft_strlen(tmp));
	else
		parser_inf_norm(line, id, index, cub);
}

static	void	parser_data(char *line, t_all *cub)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		++i;
	if (line[i] == 'R')
		parser_id(++i, line, 1, cub);
	else if (line[i] == 'F')
		parser_id(++i, line, 7, cub);
	else if (line[i] == 'C')
		parser_id(++i, line, 8, cub);
	else if (line[i++] == 'N' && line[i] == 'O')
		parser_id(++i, line, 2, cub);
	else if (line[--i] == 'S' && line[++i] == 'O')
		parser_id(++i, line, 3, cub);
	else if (line[i] == 'W' && line[++i] == 'E')
		parser_id(++i, line, 4, cub);
	else if (line[i] == 'E' && line[++i] == 'A')
		parser_id(++i, line, 5, cub);
	else if (line[--i] == 'S' && !ft_isalpha(line[++i]))
		parser_id(++i, line, 6, cub);
}

void			parser(char **av, t_all *data)
{
	char	*line;
	int		fd;
	int		num_line;

	num_line = 0;
	if ((fd = open(av[1], O_RDONLY)) && fd == -1)
		error("Error\nFile not found or can't be open", data);
	while (get_next_line(fd, &line) && num_line++ < 8)
	{
		if (ft_strlen(line) != 0)
		{
			check_tab(line, data);
			parser_data(line, data);
			if (num_line == 8)
			{
				check_all_data(data);
				break ;
			}
		}
		else
			num_line -= 1;
		free(line);
	}
	free(line);
	parser_map(fd, data);
}
