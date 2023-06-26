/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:38:17 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/29 17:35:42 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*d;

	d = (unsigned char *) s;
	while (*d != '\0')
	{
		if (*d == (unsigned char) c)
			return ((char *)d);
		d++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)d);
	else
		return (NULL);
}
