/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 23:58:31 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/21 02:09:53 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char *str, int nb)
{
	int		i;
	int		word;
	int		letter;

	i = 0;
	word = 0;
	letter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '	' || str[i] == '\n')
			i++;
		if (str[i] != '\0')
			word++;
		while (!(str[i] == ' ' || str[i] == '	'
					|| str[i] == '\n' || str[i] == '\0'))
		{
			i++;
			letter++;
		}
		if (word == nb)
			return (letter);
	}
	return (0);
}

static int		ft_assign(char **tab, char *str)
{
	int		i;
	int		word;
	int		letter;

	i = 0;
	word = 0;
	letter = 0;
	while (str[i] != '\0')
	{
		letter = 0;
		while (str[i] == ' ' || str[i] == '	' || str[i] == '\n')
			i++;
		if (str[i] != '\0')
			word++;
		else
			return (0);
		while (!(str[i] == ' ' || str[i] == '	'
					|| str[i] == '\n' || str[i] == '\0'))
			tab[word - 1][letter++] = str[i++];
		tab[word - 1][letter] = '\0';
	}
	return (0);
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	size_t	word;
	int		letter;

	word = 0;
	letter = 0;
	tab = NULL;
	word = ft_count_word(str, 0);
	tab = (char**)malloc(sizeof(char *) * (word + 1));
	while (word > 0)
	{
		letter = ft_count(str, word);
		tab[word - 1] = (char*)malloc(sizeof(tab) * letter);
		word--;
	}
	ft_assign(tab, str);
	word = ft_count_word(str, 0);
	tab[word] = 0;
	return (tab);
}
