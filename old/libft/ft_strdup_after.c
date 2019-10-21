/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:21:52 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/28 16:27:15 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_after(const char *s1, char c)
{
	int		i;
	char	*dest;
	int		j;

	i = 0;
	j = 0;
	dest = NULL;
	while (s1[i] != c)
		i++;
	if ((dest = ft_strnew(ft_strlen(&s1[++i]))))
		while (s1[i])
			dest[j++] = s1[i++];
	return (dest);
}
