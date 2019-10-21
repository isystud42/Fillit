/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:55:21 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/28 16:23:17 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	str = NULL;
	if (s1 != NULL && s2 != NULL)
		if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			ft_strcat(str, s1);
			ft_strcat(str, s2);
		}
	return (str);
}
