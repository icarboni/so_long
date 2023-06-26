/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:32:34 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/29 17:46:56 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s;
	int		d;

	i = 0;
	d = 0;
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while ((i + d) < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < ft_strlen(s1))
		{
			s[i] = s1[i];
			i++;
		}
		else
		{
			s[i + d] = s2[d];
			d++;
		}
	}
	s[i + d] = '\0';
	return (s);
}
