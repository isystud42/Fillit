/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 22:11:53 by mbouanik          #+#    #+#             */
/*   Updated: 2016/12/23 14:33:59 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_new_grid(int **old_grid, int size)
{
	int	**grid;
	int	i;
	int j;

	i = 0;
	grid = NULL;
	if (old_grid != 0)
		ft_deltabint(old_grid, size);
	grid = (int **)malloc(sizeof(int *) * (size + 4));
	while (i < size + 4)
	{
		grid[i] = (int *)malloc(sizeof(int) * size + 1);
		ft_memset(grid[i], 0, size + 1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			grid[i][j++] = 46;
		grid[i][j] = 0;
		i++;
	}
	return (grid);
}

t_bool	ft_check_place_binary(int **grid, int position,
				int size, unsigned long tetri)
{
	int	y;
	int	x;
	int y_max;
	int	x_max;

	y = position / size;
	y_max = y + 4;
	x = position % size;
	x_max = x + 4;
	while (y < y_max)
	{
		x = x_max - 4;
		while (x < x_max)
		{
			if ((tetri & 2147483648) == 2147483648)
				if (grid[y][x] != 46)
					return (FALSE);
			tetri <<= 1;
			x++;
		}
		y++;
	}
	return (TRUE);
}

void	ft_print_grid(int **grid, int size)
{
	int	y;
	int	x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(grid[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	ft_place_it_binary(int **grid, int position,
			int size, unsigned long tetri)
{
	int				y;
	int				x;
	int				y_max;
	int				x_max;
	unsigned long	letter;

	letter = tetri;
	letter <<= 16;
	letter >>= 16;
	y = position / size;
	y_max = y + 4;
	x = position % size;
	x_max = x + 4;
	while (y < y_max)
	{
		x = x_max - 4;
		while (x < x_max)
		{
			if ((tetri & 2147483648) == 2147483648)
				grid[y][x] = 65 + letter;
			tetri <<= 1;
			x++;
		}
		y++;
	}
}

void	ft_remove_it_binary(int **grid,
	int position, int size, unsigned long tetri)
{
	int	y;
	int	x;
	int y_max;
	int	x_max;

	y = position / size;
	y_max = y + 4;
	x = position % size;
	x_max = x + 4;
	while (y < y_max)
	{
		x = x_max - 4;
		while (x < x_max)
		{
			if ((tetri & 2147483648) == 2147483648)
				grid[y][x] = 46;
			tetri <<= 1;
			x++;
		}
		y++;
	}
}
