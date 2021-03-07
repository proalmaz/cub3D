/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_for_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:18:29 by vping             #+#    #+#             */
/*   Updated: 2021/03/02 22:10:12 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define A map
#define B data

static	void	check_empty_space(int lst_size, t_all *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i != lst_size)
	{
		j = 0;
		while (data->p.A[i][j] != '\0')
		{
			if ((i == 0 && data->p.A[i][j] == '0')
				|| (i == lst_size - 1 && data->p.A[i][j] == '0'))
				error("Error\nThere is an empty space next to zero", data);
			else if (data->p.A[i][j] == '0')
			{
				if (data->p.A[i][j + 1] == ' ' || data->p.A[i][j + 1] == '\0'
					|| data->p.A[i][j - 1] == ' ' || data->p.A[i][j - 1] == '\0'
					|| data->p.A[i + 1][j] == ' ' || data->p.A[i + 1][j] == '\0'
					|| data->p.A[i - 1][j] == ' ' || B->p.A[i - 1][j] == '\0')
					error("Error\nThere is an empty space next to zero", data);
			}
			++j;
		}
	}
}

static	void	plr_direction(int x, int y, t_all *data)
{
	if (data->p.A[y][x] == 'N')
	{
		data->plr.dir = (3 * PI) / 2;
		data->plr.dir_symbol = 'N';
	}
	else if (data->p.A[y][x] == 'S')
	{
		data->plr.dir = PI / 2;
		data->plr.dir_symbol = 'S';
	}
	else if (data->p.A[y][x] == 'W')
	{
		data->plr.dir = PI;
		data->plr.dir_symbol = 'W';
	}
	else if (data->p.A[y][x] == 'E')
	{
		data->plr.dir = 2 * PI;
		data->plr.dir_symbol = 'E';
	}
}

static	void	map_boundary_check(int x, int y, t_all *data, int lst_size)
{
	if (y < 0 || x < 0 || y >= lst_size || x >= (int)ft_strlen(data->p.A[y]))
		error("Error\n", data);
	if (ft_strchr(" 02NWES", data->p.A[y][x]))
	{
		if (data->p.A[y][x] == 'N' || data->p.A[y][x] == 'W'
			|| data->p.A[y][x] == 'E' || data->p.A[y][x] == 'S')
			plr_direction(x, y, data);
		if (data->p.A[y][x] == '2')
			data->p.A[y][x] = 'B';
		else
			data->p.A[y][x] = '*';
		map_boundary_check(x + 1, y, data, lst_size);
		map_boundary_check(x - 1, y, data, lst_size);
		map_boundary_check(x, y + 1, data, lst_size);
		map_boundary_check(x, y - 1, data, lst_size);
	}
}

static void		create_map(t_list **head, int lst_size, t_all *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *head;
	data->p.A = ft_calloc(lst_size + 1, sizeof(char *));
	while (tmp)
	{
		data->p.A[i++] = tmp->content;
		tmp = tmp->next;
	}
	all_tab_in_line(data->p.A[lst_size - 1], data);
	check_symbols_map(lst_size, data);
	check_empty_space(lst_size, data);
	map_boundary_check(data->p.playr_x, data->p.playr_y, data, lst_size);
	data->p.size_map = lst_size;
	free_lst_map(head);
}

void			parser_map(int fd, t_all *cub)
{
	char	*line;
	t_list	*head;

	head = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	if (close(fd) == -1)
		error("Error\nCouldn't close the file", cub);
	create_map(&head, ft_lstsize(head), cub);
}
