/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_present.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:05:30 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/29 12:05:49 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_is_present(char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c || i != ft_strlen(str))
		return (TRUE);
	return (FALSE);
}
