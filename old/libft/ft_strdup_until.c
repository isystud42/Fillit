/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:05:43 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/28 16:29:01 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_until(const char *s1, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if ((dest = ft_strnew((ft_count_until(s1, c)))))
		while (s1[i] != c && s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	return (dest);
}
