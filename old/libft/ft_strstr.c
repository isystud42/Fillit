/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:16:57 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/16 11:55:30 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!ft_strlen(little))
		return ((char*)big);
	while (big[i])
	{
		while (big[i + j] == little[j] && little[j])
			j++;
		if (little[j] == '\0')
			return ((char*)&big[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
