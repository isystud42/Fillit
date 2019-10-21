/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:32:14 by mbouanik          #+#    #+#             */
/*   Updated: 2017/01/07 17:59:13 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool		ft_fill_it(int **grid, unsigned long *tetri, int size, int position)
{
	if (*tetri == 0)
		return (TRUE);
	if (position == size * size)
		return (FALSE);
	if (!(ft_check_place_binary(grid, position, size, *tetri)))
		return (ft_fill_it(grid, tetri, size, position + 1));
	else
	{
		ft_place_it_binary(grid, position, size, *tetri);
		if (ft_fill_it(grid, (tetri + 1), size, 0) == FALSE)
		{
			ft_remove_it_binary(grid, position, size, *tetri);
			return (ft_fill_it(grid, tetri, size, position + 1));
		}
	}
	return (TRUE);
}

int			main(int ac, char **av)
{
	int					**grid;
	char				***pieces;
	unsigned long		*binary;
	int					nb_pieces;
	int					size;

	if (!(pieces = ft_oktab(ac, av)))
		return (0);
	nb_pieces = ft_cp(ac, av);
	binary = (unsigned long *)malloc(sizeof(unsigned long) * nb_pieces + 1);
	size = 0;
	while (size < nb_pieces)
	{
		binary[size] = ft_name(size, ft_binary(pieces[size], 0, 0));
		size++;
	}
	binary[size] = 0;
	size = 0;
	while (nb_pieces * 4 > size * size)
		size++;
	grid = ft_new_grid(grid, size);
	while (!(ft_fill_it(grid, binary, size, 0)))
		grid = ft_new_grid(grid, ++size);
	ft_print_grid(grid, size);
	return (0);
}
