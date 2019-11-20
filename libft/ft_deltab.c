/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 04:29:49 by isy               #+#    #+#             */
/*   Updated: 2019/11/19 20:23:51 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deltab(char ***double_tab)
{
	char **save;

	if (double_tab)
	{
		save = *double_tab;
		while (*save)
		{

			free(*save);
			(save)++;
		}
		free(*double_tab);
		*double_tab = NULL;
	}
}
