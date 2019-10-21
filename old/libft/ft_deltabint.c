/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltabint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:22:32 by mbouanik          #+#    #+#             */
/*   Updated: 2016/12/22 20:30:28 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_deltabint(int **grid, int size)
{
	int i;

	i = 0;
	if (grid != 0)
	{
		while (i < size)
		{
			free((grid)[i]);
			(grid)[i] = 0;
			i++;
		}
		free(grid);
		grid = 0;
	}
}
