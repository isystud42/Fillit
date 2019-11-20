/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:04:20 by idsy              #+#    #+#             */
/*   Updated: 2019/11/20 14:09:21 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncount(char *str, char c, int n)
{
	int	c_count;

	c_count = 0;
	if (!str)
		return (0);
	while (*str && n > 0)
	{
		if (*str == c)
			c_count += 1;
		str++;
		n--;
	}
	return (c_count);
}
