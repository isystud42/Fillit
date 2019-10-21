/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puttsche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 23:16:29 by puttsche          #+#    #+#             */
/*   Updated: 2016/12/16 11:37:40 by puttsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verifpiece(char ***tab, int a, int b)
{
	int		c;
	int		connex;

	c = -1;
	if (tab != NULL)
		while (tab[++a])
		{
			connex = 0;
			while (tab[a][++b])
			{
				while (++c < 4)
					if (tab[a][b][c] == '#')
					{
						if ((c != 3) && (tab[a][b][c + 1] == '#'))
							connex++;
						if ((b != 3) && (tab[a][b + 1][c] == '#'))
							connex++;
					}
				c = -1;
			}
			if (connex < 3)
				return (0);
			b = -1;
		}
	return (1);
}

char	***ft_oktab(int ac, char **av)
{
	int		piece;
	char	***tab;
	int		test;

	test = ft_regrouptest(ac, av);
	if (test == 0)
		return (NULL);
	tab = ft_tabtabtabcreat(ac, av);
	tab = ft_filltab(tab, ft_open(ac, av), 0, 0);
	piece = ft_verifpiece(tab, -1, -1);
	if (piece == 1)
		return (tab);
	if (piece == 0)
		piece = ft_error(2);
	return (NULL);
}
