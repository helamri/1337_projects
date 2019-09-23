/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:57:59 by helamri           #+#    #+#             */
/*   Updated: 2018/12/29 18:58:01 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *addr;

	if (lst == NULL)
		return (NULL);
	if (!(fresh = (t_list *)malloc(sizeof(t_list))))
		return (0);
	fresh = f(ft_lstnew(lst->content, lst->content_size));
	addr = fresh;
	lst = lst->next;
	while (lst)
	{
		if (!(addr->next = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		lst = lst->next;
		addr = addr->next;
	}
	return (fresh);
}
