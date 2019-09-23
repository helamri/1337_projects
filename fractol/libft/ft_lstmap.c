/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:53:25 by helamri           #+#    #+#             */
/*   Updated: 2018/10/29 11:53:49 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;
	t_list	*tmp;

	head = (t_list*)malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	tmp = NULL;
	while (lst != NULL)
	{
		list = (t_list*)malloc(sizeof(t_list));
		if (list == NULL)
			return (NULL);
		list = (f)(lst);
		if (tmp != NULL)
			tmp->next = list;
		else
			head = list;
		tmp = list;
		lst = lst->next;
	}
	return (head);
}
