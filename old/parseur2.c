/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puttsche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:39:41 by puttsche          #+#    #+#             */
/*   Updated: 2016/12/16 11:33:11 by puttsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nbchar(int ac, char **av)
{
	char	*tab;
	int		x;
	int		nbchar;

	x = 0;
	tab = ft_open(ac, av);
	nbchar = 0;
	while (tab[x] != '\0')
	{
		if (tab[x] == '\n' && ((tab[x + 1] == '\n') || tab[x + 1] == '\0'))
		{
			if (nbchar != 4)
				return (0);
			nbchar = 0;
		}
		if (tab[x] == '#')
			nbchar++;
		x++;
	}
	if (tab[x] == '\0')
		return (1);
	return (0);
}

int		ft_error(int x)
{
	if (x == 1)
		ft_putendl("usage : ./fillit <file>.");
	if (x == 2)
		ft_putendl("error");
	return (0);
}

int		ft_regrouptest(int ac, char **av)
{
	int		x;
	int		fd;
	int		test;

	test = 0;
	x = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || ac != 2)
		return (ft_error(1));
	x = ft_cp(ac, av);
	if (x <= 0 || x >= 27)
		return (ft_error(2));
	x = ft_verifchar(ac, av);
	if (x == 0)
		return (ft_error(2));
	x = ft_verifgrille(ac, av);
	if (x == 0)
		return (ft_error(2));
	x = ft_nbchar(ac, av);
	if (x == 0)
		return (ft_error(2));
	if (x == 1)
		return (1);
	return (0);
}

char	***ft_tabtabtabcreat(int ac, char **av)
{
	char	***tab3d;
	int		cp;
	int		a;
	int		b;

	a = 0;
	b = 0;
	cp = ft_cp(ac, av);
	tab3d = (char***)malloc(sizeof(char**) * cp + 1);
	tab3d[cp] = NULL;
	while (a < cp)
	{
		tab3d[a] = (char**)malloc(sizeof(char*) * 5);
		tab3d[a][4] = NULL;
		while (b < 4)
		{
			tab3d[a][b] = ft_strnew(4);
			b++;
		}
		a++;
		b = 0;
	}
	if (tab3d != NULL)
		return (tab3d);
	return (NULL);
}

char	***ft_filltab(char ***tab3d, char *buf, int a, int b)
{
	int		x;
	int		c;

	c = 0;
	x = 0;
	if (tab3d != NULL)
		while (tab3d[a])
		{
			while (tab3d[a][b])
			{
				while (c < 4)
				{
					while (buf[x] == '\n')
						x++;
					tab3d[a][b][c] = buf[x];
					x++;
					c++;
				}
				b++;
				c = 0;
			}
			a++;
			b = 0;
		}
	return (tab3d);
}
