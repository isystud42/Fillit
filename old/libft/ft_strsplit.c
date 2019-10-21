/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:11:38 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/23 17:35:36 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_assign(char **strtab, char const *s, char c, int index)
{
	int		i;
	int		letter;
	int		wordnum;
	int		letternum;

	i = 0;
	letter = 0;
	wordnum = 0;
	letternum = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		index = i;
		if (s[i] != '\0')
			while (s[i] != c && s[i] && ++letter)
				i++;
		strtab[wordnum] = (char *)malloc(sizeof(char) * letter + 1);
		while (letternum < letter)
			strtab[wordnum][letternum++] = s[index++];
		strtab[wordnum][letter] = '\0';
		letter = 0;
		letternum = 0;
		wordnum++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		index;
	char	**strtab;

	index = 0;
	strtab = NULL;
	if (s == NULL || c == 0)
		return (NULL);
	if (!(strtab = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (NULL);
	ft_assign(strtab, s, c, index);
	strtab[ft_count_word(s, c)] = 0;
	return (strtab);
}
