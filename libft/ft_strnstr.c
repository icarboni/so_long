/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:15:39 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/29 17:48:34 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t			c1;
	size_t			c2;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) big;
	s2 = (unsigned char *) little;
	c1 = 0;
	c2 = 0;
	if (s2[0] == '\0')
		return ((char *) s1);
	while (s1[c1] != '\0' && c1 < len)
	{
		while ((s1[c1 + c2] == s2[c2])
			&& (s1[c1 + c2] != '\0') && (c1 + c2) < len)
		{
			c2++;
		}
		if (s2[c2] == '\0')
			return ((char *)s1 + c1);
		c1++;
		c2 = 0;
	}
	return (0);
}
