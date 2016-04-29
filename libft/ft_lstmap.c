/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:16:01 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/05 15:36:57 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *p;
	t_list *p2;

	result = NULL;
	if (lst == NULL || (*f) == NULL)
		return (NULL);
	p2 = (*f)(lst);
	if ((result = ft_lstnew(p2->content, p2->content_size)) != NULL)
	{
		p = result;
		lst = lst->next;
		while (lst != NULL)
		{
			p2 = (*f)(lst);
			if (!(p->next = ft_lstnew(p2->content, p2->content_size)))
				return (NULL);
			p = p->next;
			lst = lst->next;
		}
	}
	return (result);
}
