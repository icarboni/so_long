/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:33:14 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/29 17:15:28 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = (unsigned char *) s;
	while (i < n)
	{
		if (d[i] == (unsigned char) c)
			return ((void *) &s[i]);
		i++;
	}
	return (NULL);
}
