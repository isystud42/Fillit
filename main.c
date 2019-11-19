/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:17:11 by idsy              #+#    #+#             */
/*   Updated: 2019/11/18 14:17:16 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
