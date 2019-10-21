/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:23:45 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/19 18:05:07 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;

	new = NULL;
	if (lst != NULL && (*f))
	{
		tmp = f(lst);
		new = ft_lstnew(tmp->content, tmp->content_size);
		free(tmp);
		new->next = ft_lstmap(lst->next, f);
	}
	return (new);
}
