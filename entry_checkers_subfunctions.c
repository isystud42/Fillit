/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_checkers_subfunctions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:22:51 by idsy              #+#    #+#             */
/*   Updated: 2019/11/21 14:49:57 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This file is the file containing all the subfuctions necessary for the
**	Checking of the entry file. Main functions are in entry_checkers.c
*/

#include "fillit.h"

/*
** Check_hash_links_number basically counts the numbers of links the current #
** has, and is carefull not trying to access mamory outside of the file_string
**	It just uses a little while loop that indentificates the lengt of the tetri
** left from the current #
*/

static	int	check_hash_links_number(char *file_string)
{
	int	link_count;
	int	tet_len;

	link_count = 0;
	tet_len = 0;
	while (file_string[tet_len] != '\0')
	{
		tet_len++;
		if (file_string[tet_len] == '\n' && file_string[tet_len + 1] == '\n')
			break ;
	}
	tet_len++;
	if (tet_len >= 5 && (*(file_string + 5) == '#'))
		link_count++;
	if (tet_len >= 1 && (*(file_string + 1) == '#'))
		link_count++;
	if (tet_len <= 15 && (*(file_string - 5) == '#'))
		link_count++;
	if (tet_len <= 19 && (*(file_string - 1) == '#'))
		link_count++;
	if (link_count == 0)
		return (-1);
	if (link_count == 1)
		return (1);
	return (0);
}

/*
** Check_hash_links_snippet, is just a way to avoid the 25 lines rule of the
** norm. Indeed the original Check_hash_links_format, could have avoided the
** usage of this subfunction, but it was 1 line too long.
** Basically a norm supposed to help use to produce some clean code, just made
** me do something dirty
*/

int			check_hash_links_snippet(char **file_string, int *one_link_count)
{
	int	ret;

	if (**file_string == '#')
	{
		if ((ret = check_hash_links_number(*file_string)) == -1)
			return (-1);
		*one_link_count += ret;
	}
	return (0);
}

/*
** Check_line is the function that is supposed to check_individual lines
** It checks the number of chars by lines, verifies that all of those are #/.
** and edits the hash_counter from the main function to ensure the final number
** of # isn't above 4
*/

int			check_line(char **file_string, int *hash_count)
{
	int	char_nb;

	if (!*file_string)
		return (-1);
	char_nb = 0;
	while (**file_string != '\n' && **file_string)
	{
		if (**file_string == '#')
			++*hash_count;
		if (**file_string != '.' && **file_string != '#')
			return (-1);
		char_nb++;
		++*file_string;
	}
	if (char_nb != 4 || **file_string != '\n' || *hash_count > 4)
		return (-1);
	if (**file_string)
		++*file_string;
	return (*hash_count);
}
