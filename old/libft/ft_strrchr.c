/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:56:20 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/16 11:55:14 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t index;

	i = 0;
	index = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (char)c)
			index = i;
		i++;
	}
	if (s[index] == (char)c)
		return ((char*)&s[index]);
	return (NULL);
}
