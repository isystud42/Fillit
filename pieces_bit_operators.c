/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_bit_operators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:37:14 by idsy              #+#    #+#             */
/*   Updated: 2019/11/21 15:55:57 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** To check if a grid space is available, we just have to check if the binary
** operator && is not valuable between the final form of the tetri and a short
** created from the 4 lines;
*/

int			check_grid_space(long *grid, short piece,
							short line, short line_pos)
{
	short	grd_bits;
	short	foo;

	foo = -1;
	grd_bits = 0;
	while (++foo < 4)
	{
		grd_bits <<= 4;
		grd_bits = (grd_bits | ((grid[line + foo] >> (28 - line_pos)) & 15));
	}
	if ((piece & grd_bits) != 0)
	{
		return (1);
	}
	return (0);
}

/*
** i want to get to do an binary add between the piece of the grid
** and the tetri line i could convert tetri line into longs and just
** do a binary operator between them after shifting?
*/

void		insert_piece(long **grid, long piece,
							short line, short line_pos)
{
	short	foo;
	long	comparison;

	foo = 0;
	piece <<= 16 - line_pos;
	comparison = (0xF0000000 >> line_pos);
	while (foo++ < 4)
	{
		(*grid)[line++] |= (piece & comparison);
		piece <<= 4;
	}
}

void		remove_piece(long **grid, long piece, short line, short line_pos)
{
	short	foo;
	long	comparison;

	foo = 0;
	piece <<= 16 - line_pos;
	comparison = (0xF0000000 >> line_pos);
	while (foo++ < 4)
	{
		(*grid)[line++] ^= (piece & comparison);
		piece <<= 4;
	}
}

/*
** Basically saving the position on the last 11 bits of the piece binary
*/

void		save_piece_pos(long *pieces, short position)
{
	long	position_save_bits;

	position_save_bits = (position << 21);
	*pieces |= position_save_bits;
}
