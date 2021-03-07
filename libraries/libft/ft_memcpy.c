/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:18:40 by vping             #+#    #+#             */
/*   Updated: 2020/11/16 15:30:47 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcpy: копирует n байт из массива на который
** указывает аргумент src, в массив
** на который указывает аргумент dst.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *ptr;

	ptr = dest;
	if (!src && !dest)
		return (NULL);
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (ptr);
}
