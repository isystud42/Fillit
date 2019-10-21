/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:03:27 by mbouanik          #+#    #+#             */
/*   Updated: 2016/12/22 21:12:09 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long		ft_left_binary(unsigned int binary)
{
	unsigned long	a;
	unsigned long	b;
	unsigned long	c;

	b = 4026531840;
	a = 268435456;
	c = 2306867200;
	while (binary <= 2147483648)
		binary <<= 1;
	if ((binary & b) == b)
		return (binary);
	while ((binary & a) == a || ((binary & c) == c))
		binary >>= 1;
	return (binary);
}

unsigned long		ft_name(int c, unsigned long binary)
{
	binary += c;
	return (binary);
}

unsigned long		ft_binary(char **tab_tetri, int i, int j)
{
	unsigned long	binary;
	unsigned long	save;
	unsigned long	a;

	a = 0;
	binary = 0;
	while (tab_tetri[i])
	{
		j = 0;
		while (tab_tetri[i][j])
		{
			if (tab_tetri[i][j] == '#')
				a = 1;
			else
				a = 0;
			binary += a;
			save = binary;
			if (tab_tetri[i][j])
				binary <<= 1;
			j++;
		}
		i++;
	}
	return (ft_left_binary(save));
}
