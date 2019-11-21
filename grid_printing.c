/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_printing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:22:48 by idsy              #+#    #+#             */
/*   Updated: 2019/11/21 15:50:50 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** While printing the grid, we're basically reverting back to the normal system
** of having a array of strings. The size of the grid permits us to affect the
** position information in the piece binary to a line
*/

static	char	**initialise_displayed_grid(short grid_size)
{
	char	**displayed_grid;
	short	foo;

	foo = 0;
	if (!(displayed_grid = malloc(grid_size * sizeof(char *) + 1)))
		return (NULL);
	while (foo < grid_size)
	{
		if (!(displayed_grid[foo] = malloc(grid_size * sizeof(char) + 1)))
			return (NULL);
		ft_memset((void *)displayed_grid[foo], '.', grid_size);
		displayed_grid[foo++][grid_size] = '\0';
	}
	displayed_grid[foo] = NULL;
	return (displayed_grid);
}

/*
** What we want to do here is to identify the placement bits in the binary of
** the piece, translate this position to a position in a line of the grid
** then take the bits responsible of the info of a piece and progressively
** place them in the lines of the grid associated
*/

void			place_pieces_in_displayed_grid(char **displayed_grid,
			short grid_size, long *pieces)
{
	short	line;
	short	line_pos;
	short	foo;
	short	bar;
	short	letter;

	while (*pieces)
	{
		line = (((*pieces & 0XFFE00000) >> 21) / grid_size);
		line_pos = (((*pieces & 0XFFE00000) >> 21) % grid_size);
		letter = ((*pieces & 0X001F0000) >> 16);
		foo = 4;
		while (foo-- >= 1)
		{
			bar = 4;
			while (bar-- >= 1)
			{
				if (*pieces & 0x1)
					displayed_grid[line + foo][line_pos + bar] = letter + 65;
				*pieces >>= 1;
			}
		}
		pieces++;
	}
}

/*
** convert and display is the man function responsible to convert pieces
** back from their simplified bits to a name, position.
*/

int				convert_and_display_grid(long *pieces, short grid_size)
{
	char	**displayed_grid;
	int		foo;

	if (!(displayed_grid = initialise_displayed_grid(grid_size)))
		return (-1);
	place_pieces_in_displayed_grid(displayed_grid, grid_size, pieces);
	foo = 0;
	while (foo < grid_size)
		ft_putendl(displayed_grid[foo++]);
	ft_deltab(&displayed_grid);
	return (0);
}
