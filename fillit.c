/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:02:21 by idsy              #+#    #+#             */
/*   Updated: 2019/11/21 15:33:50 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Le backtracking:
** try to place a piece, if it works, great. Just do it for the next piece
** If it doesn't work, Try with the next position. If it doesn't work with
** any of them, Get a bigger grid... Brute force style.
*/

int		fill_it_backtracking(long *grid, short gd_size,
								short position, long *pieces)
{
	short	line;
	short	line_pos;

	if (*pieces == 0)
		return (0);
	if (position == gd_size * gd_size)
		return (1);
	line = position / gd_size;
	line_pos = position % gd_size;
	if ((check_grid_space(grid, *pieces, line, line_pos)) == 1)
	{
		return (fill_it_backtracking(grid, gd_size, position + 1, pieces));
	}
	else
	{
		insert_piece(&grid, (long)*pieces, line, line_pos);
		if (fill_it_backtracking(grid, gd_size, 0, pieces + 1) == 1)
		{
			remove_piece(&grid, (long)*pieces, line, line_pos);
			return (fill_it_backtracking(grid, gd_size, position + 1, pieces));
		}
		else
			save_piece_pos(pieces, position);
	}
	return (0);
}

/*
** The main calls all principal functions title of function should be clear.
*/

int		main(int argc, char **argv)
{
	long	*pieces;
	short	gd_size;
	long	*grid;

	if (!(pieces = parsing_of_the_file(argc, argv)))
		return (-1);
	gd_size = find_out_minimal_grid_size(pieces);
	if (!(grid = generate_grid(gd_size)))
		return (-1);
	while ((fill_it_backtracking(grid, gd_size, 0, pieces)))
		grid = resize_grid(grid, ++gd_size);
	convert_and_display_grid(pieces, gd_size);
	return (0);
}
