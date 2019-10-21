/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 05:42:53 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/21 02:06:17 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t a;
	size_t ld;

	i = 0;
	a = 0;
	ld = (ft_strlen(dst) + ft_strlen(src));
	while (dst[i] && i < size - 1)
		i++;
	if (dst[i] != '\0' || !(size))
		return (ft_strlen(src) + size);
	while ((i + a) < size - 1 && src[a])
	{
		*(dst + (i + a)) = *(src + a);
		a++;
	}
	dst[i + a] = '\0';
	return (ld);
}
