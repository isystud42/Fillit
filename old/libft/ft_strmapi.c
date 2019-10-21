/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:37:27 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/16 11:54:22 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = NULL;
	if (s == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (s != NULL && (*f) && str != NULL)
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
	return (str);
}
