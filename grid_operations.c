/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 08:37:22 by idsy              #+#    #+#             */
/*   Updated: 2019/11/18 13:31:47 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

long	*resize_grid(long *grid, short size)
{
	short	foo;
	long	shifted_bits;

	foo = 0;
	shifted_bits = (0xFFFFFFFF >> size);
	while (grid && foo < 32)
	{
		if (foo < size)
			grid[foo++] = shifted_bits;
		else
			grid[foo++] = 0xFFFFFFFF;
	}
	return (grid);
}

long	*generate_grid(short size)
{
	short	foo;
	long	*new_grid;
	long	shifted_bits;

	if (!(new_grid = (long*)malloc(sizeof(long) * 32)))
		return (NULL);
	foo = 0;
	shifted_bits = (0xFFFFFFFF >> size);
	while (foo < 32)
	{
		if (foo < size)
			new_grid[foo++] = shifted_bits;
		else
			new_grid[foo++] = 0xFFFFFFFF;
	}
	return (new_grid);
}

int		find_out_minimal_grid_size(long *pieces)
{
	int		grid_size;
	int		pieces_count;

	if (!pieces)
		return (0);
	grid_size = 2;
	pieces_count = 0;
	while (*(pieces++))
		pieces_count++;
	while (pieces_count * 4 > grid_size * grid_size)
		grid_size++;
	return (grid_size);
}

/*
** take position, divide it by the grid size to get the line, and take the modu
** of it to get the position in theline. Then compared the 4 bits starting
** to the position of this line to the first 4 bits of the teri and repeat of
** each line of the tetriminos.
*/
