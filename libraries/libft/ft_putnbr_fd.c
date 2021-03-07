/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:45:58 by vping             #+#    #+#             */
/*   Updated: 2020/11/04 16:35:34 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr_fd: Выводит целое число 'n'
** в указанный файл дескриптор.
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + '0'), fd);
}
