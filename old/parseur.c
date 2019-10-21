/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puttsche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:34:45 by puttsche          #+#    #+#             */
/*   Updated: 2016/12/16 11:37:08 by puttsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_open(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	fd = ac;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	close(fd);
	return (ft_strdup(buf));
}

int			ft_cp(int ac, char **av)
{
	int		x;
	char	*buf;
	int		nbpiece;

	nbpiece = 0;
	if (ac != 2)
		return (0);
	buf = ft_open(ac, av);
	x = 0;
	while (buf[x])
	{
		if (buf[x] == '\n' && (buf[x + 1] == '\n' || buf[x + 1] == '\0'))
			nbpiece++;
		x++;
	}
	return (nbpiece);
}

int			ft_verifchar(int ac, char **av)
{
	int		x;
	char	*buf;

	buf = ft_open(ac, av);
	x = 0;
	while (buf[x])
	{
		if (buf[x] != '.' && buf[x] != '#' && buf[x] != '\n' && buf[x] != '\0')
		{
			free(buf);
			return (0);
		}
		x++;
	}
	if (x == ((ft_cp(ac, av) * 21) - 1))
	{
		free(buf);
		return (1);
	}
	free(buf);
	return (0);
}

int			ft_verifgrille(int ac, char **av)
{
	int		*suite;
	int		xsuite;
	char	*string;
	int		i;
	int		cp;

	i = 0;
	cp = ft_cp(ac, av);
	string = ft_open(ac, av);
	xsuite = 0;
	suite = ft_gensuite(ac, av, ((cp * 5) - 1));
	while ((i < (cp * 5) - 1))
	{
		if ((string[suite[xsuite]]) != '\n')
		{
			free(string);
			return (0);
		}
		xsuite++;
		i++;
	}
	free(string);
	return (1);
}

int			*ft_gensuite(int ac, char **av, int z)
{
	int		x;
	int		y;
	int		i;
	int		*tab;

	tab = malloc(sizeof(int) * ((ft_cp(ac, av) * 5) - 1));
	x = 4;
	y = 0;
	i = 1;
	tab[0] = 4;
	while (i < z)
	{
		x += 5;
		y++;
		if ((y == 3 && x < 30) || (y == 4 && x > 30))
		{
			tab[i] = x;
			y = 0;
			x++;
			i++;
		}
		tab[i] = x;
		i++;
	}
	return (tab);
}
