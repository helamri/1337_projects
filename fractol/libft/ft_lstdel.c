/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:51:54 by helamri           #+#    #+#             */
/*   Updated: 2018/10/29 11:52:13 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;
	t_list	*tmp;

	list = *alst;
	while (list)
	{
		tmp = list->next;
		(*del)(list->content, list->content_size);
		free(list);
		list = tmp;
	}
	*alst = NULL;
}
