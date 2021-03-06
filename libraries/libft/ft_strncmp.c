/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:37:53 by vping             #+#    #+#             */
/*   Updated: 2020/11/13 15:47:50 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strncmp: побайтно сравнивает коды
** символов двух строк, на которые указывают
** аргументы функции.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 != '\0' && (n > 0))
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 != *s2 && n > 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
