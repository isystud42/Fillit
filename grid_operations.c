/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 08:37:22 by idsy              #+#    #+#             */
/*   Updated: 2019/11/21 15:42:51 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Grid is a array of long, Each long represents a line of the grid, and each
** bit represents the disponibility of a unit. If the bit is on a 0, it's free
** if it's on 1 it's not.
*/

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

/*
** When creating a grid, we initiate each of the 32 bits of a long to 1
** 0xFFFFFFFF = 1111 1111 1111 1111		1111 1111 1111 1111
** then we shift 'size' number of longs to the right of 'size number of bits
** to create a clear space.
*/

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

/*
** To find out the minimal grid size we just need to know how much tetris
** we have, so we can know the number of # we have, and that number is
** the minimal space needed to be able to fit every tetri inside.
** keep in mind tha space = grid_size * grid_size
*/

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
