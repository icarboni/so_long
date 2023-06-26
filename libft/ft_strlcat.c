/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:25:04 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/27 18:29:32 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l1;
	size_t	l2;
	size_t	c3;
	size_t	c4;

	l1 = ft_strlen(dst);
	l2 = ft_strlen(src);
	c3 = 0;
	c4 = l1;
	if (size == 0 || size <= l1)
	{
		return (l2 + size);
	}
	while ((c4 < (size - 1)) && c3 < l2)
	{
		dst[c4] = src[c3];
		c3++;
		c4++;
	}
	dst[c4] = '\0';
	return (l1 + l2);
}
