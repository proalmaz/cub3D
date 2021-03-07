/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:29:48 by vping             #+#    #+#             */
/*   Updated: 2021/02/23 14:08:38 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strdup: дублирует строку, на
** которую указывает аргумент str.
*/

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	if (!(dest = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
