/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:42:37 by helamri           #+#    #+#             */
/*   Updated: 2018/10/17 12:12:39 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *alst;
	while (ptr)
	{
		temp = ptr;
		ft_lstdelone(&ptr, del);
		ptr = temp->next;
	}
	*alst = NULL;
}
