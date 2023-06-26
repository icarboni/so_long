/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:07:20 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/30 15:54:50 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n;

	new = NULL;
	if (lst == NULL && f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		n = ft_lstnew(f(lst->content));
		if (!n)
		{
			ft_lstclear(&new, *del);
			return (NULL);
		}
		ft_lstadd_back(&new, n);
		lst = lst->next;
	}
	return (new);
}
