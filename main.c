/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:54:04 by vping             #+#    #+#             */
/*   Updated: 2021/03/02 21:54:07 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all		data;

	check_errors_arg(argc, argv, &data);
	parser(argv, &data);
	start_cub3d(&data, argc);
	return (0);
}
