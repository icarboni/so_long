/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:17:55 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/30 12:20:15 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	i;
	size_t	size_use;

	i = -1;
	len_s = ft_strlen(s);
	if (start > len_s || len_s == 0)
		size_use = 0;
	else if ((len_s - start) < len)
		size_use = len_s - start;
	else
		size_use = len;
	sub = (char *)malloc(sizeof(char) * (size_use + 1));
	if (sub == NULL)
		return (NULL);
	while (++i < (size_use))
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}
