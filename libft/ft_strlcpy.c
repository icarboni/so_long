/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:16:41 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/29 17:47:15 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			c;
	size_t			lenght;

	c = 0;
	lenght = 0;
	while (src[lenght] != '\0')
		lenght++;
	if (size != 0)
	{	
		while (c < (size - 1) && (src[c] != '\0'))
		{
			*(dst + c) = src[c];
			c++;
		}
		*(dst + c) = '\0';
	}
	return (lenght);
}
