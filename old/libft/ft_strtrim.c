/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:15:32 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/16 11:55:42 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		t;
	char	*str;

	str = NULL;
	i = 0;
	j = 0;
	t = 0;
	if (s != NULL)
	{
		j = ft_strlen(s) - 1;
		while ((s[i] == '\t' || s[i] == ' ' || s[i] == '\n') && (s[i]))
			i++;
		while ((s[j] == '\t' || s[j] == ' ' || s[j] == '\n') &&
				(j > i && s[j]))
			j--;
		str = ft_strnew(j - i + 1);
		if (str != NULL)
			while (i <= j)
				str[t++] = s[i++];
	}
	return (str);
}
