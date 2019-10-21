/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:01:26 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/16 11:54:15 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	str = NULL;
	str = ft_strnew(ft_strlen(s));
	if (s != NULL && (*f) && str != NULL)
		while (s[i] && i < ft_strlen(s))
		{
			str[i] = f(s[i]);
			i++;
		}
	return (str);
}
