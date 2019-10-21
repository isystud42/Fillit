/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:11:15 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/20 09:07:59 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_assign(char const *s, char c, int i)
{
	size_t			letter;
	size_t			letternum;
	size_t			index;
	t_list			*new;
	char			*str;

	new = NULL;
	str = NULL;
	letter = 0;
	letternum = 0;
	index = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	index = i;
	while (s[i] != c && s[i] && ++letter)
		i++;
	if (!(str = ft_strnew(letter)))
		return (NULL);
	while (letternum < letter)
		str[letternum++] = s[index++];
	new = ft_lstnew(str, ft_strlen(str));
	new->next = ft_assign(&s[i], c, 0);
	return (new);
}

t_list				*ft_lststr_split(char *str, char c)
{
	t_list			*lststr;

	lststr = NULL;
	lststr = ft_assign(str, c, 0);
	return (lststr);
}
