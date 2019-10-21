/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:59:22 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/19 05:12:05 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_assign_num(char *nbr, int n, int i)
{
	if (n > 0)
		ft_assign_num(nbr, n / 10, --i);
	nbr[i] = n % 10 + '0';
}

static void		ft_sign(int *n, int *s)
{
	if (*n < 0)
	{
		*s = 1;
		*n *= -1;
	}
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		i;
	int		index;
	int		neg;

	neg = 0;
	nbr = NULL;
	if ((i = 0) || n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ft_sign(&n, &neg);
	index = n;
	while (index != 0 && ++i)
		index /= 10;
	if (!(nbr = ft_strnew(i + neg)))
		return (NULL);
	if (neg)
	{
		nbr[0] = '-';
		ft_assign_num(&nbr[1], n, i);
	}
	else
		ft_assign_num(nbr, n, i);
	return (nbr);
}
