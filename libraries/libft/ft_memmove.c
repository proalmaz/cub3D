/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:46:39 by vping             #+#    #+#             */
/*   Updated: 2020/11/03 15:50:26 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memmove: копирует n байт из массива,
** на который указывает аргумент source,
** в массив, на который указывает аргумент destination.
*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dst);
}
