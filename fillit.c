/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:02:21 by idsy              #+#    #+#             */
/*   Updated: 2019/09/30 10:04:35 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	chopper les pieces par parsing, le stockers en informations minimales
**	si seulement 1 piece, commencer par une grille capable d'accepter
**	tous les points, soit nb_pieces * 4 < grid_size * grid_size;
**
*/

void			print_grid(int **grid, int size)
{}

static	int		find_out_minimal_grid_size(char **pieces)
{
	int		grid_size;
	int		pieces_count;

	grid_size = 2;
	pieces_count = 0;
	while (*pieces[pieces_count])
		pieces_count++;
	while (pieces_count * 4 > grid_size * grid_size)
		grid_size++;
	return (grid_size);
}

static	char	**generate_grid()
{
	char	**grid;
	return (grid);
}

int				fill_it_backtracking(char **grid, int grid_size, char **pieces, int position)
{}

int				main(int argc, char **argv)
{
	char	**pieces;
	int		grid_size;
	char	**grid;

	if (!(pieces = parsing_of_the_file(argc,argv)))
		return (-1);
	grid_size = find_out_minimal_grid_size(pieces);
	grid = generate_grid(grid,grid_size);
	while (!(fill_it_backtracking(grid,grid_size,pieces,0)))
		grid = generate_grid(grid,++grid_size);
	print_grid(grid,grid_size);
	return (0);
}
