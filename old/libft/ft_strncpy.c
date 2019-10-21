/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:02:09 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/16 11:54:51 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t srclen;

	i = 0;
	srclen = ft_strlen(src);
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (srclen < len)
	{
		dst[i++] = '\0';
		srclen++;
	}
	return (dst);
}
