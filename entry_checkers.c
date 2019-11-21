/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:04:21 by idsy              #+#    #+#             */
/*   Updated: 2019/11/21 15:18:29 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is containing the main checking functions of the entry file
** Some of those function use subfunctions. These subft can be found in:
**		entry_checkers_subfunctions.c
*/

#include "fillit.h"

/*
** Check_tetri: A tetrimino should have 4 lines with no more than 4 hashs
** if there is a following tetriminos, it shoulb be separated by a '\n'
*/

int			check_tetri(char *file_string)
{
	int	hash_count;
	int	line_count;

	hash_count = 0;
	line_count = 0;
	while (*file_string && *file_string != '\n')
	{
		if (check_line(&file_string, &hash_count) == -1)
			return (-1);
		line_count++;
	}
	if (line_count != 4 || hash_count != 4)
		return (-1);
	if (*file_string == '\n')
		return (check_tetri(file_string + 1));
	return (0);
}

/*
** check_hash_links_format is charged to check that all the # contained in a
** tetrimino are connected to each other. It calls a snippet that you can find
** in the subfunctions file.
**	If every hash has a connection to another #
**	and if no more than 3 # are connected to only 1 # then the tetri is valid
*/

int			check_hash_links_format(char *file_string)
{
	int	one_link_count;

	one_link_count = 0;
	while (*file_string)
	{
		if (*file_string == '\n')
		{
			if (file_string[1] == '\n' || !file_string[1])
			{
				if (one_link_count > 3)
					return (-1);
				one_link_count = 0;
				file_string++;
			}
			file_string++;
			continue ;
		}
		if (check_hash_links_snippet(&file_string, &one_link_count) == -1)
			return (-1);
		file_string++;
	}
	return (0);
}

/*
** check_space_and_number checks if there is less than 26 tetris
** and if there is multiple tetris, that they are well spaced between
** themselves and separated by a \n
*/

int			check_space_and_number(char *file_string)
{
	int	char_count;
	int	tetri_count;

	tetri_count = 0;
	while (*file_string && tetri_count < 28)
	{
		char_count = 0;
		while (char_count < 20 && *file_string)
		{
			char_count++;
			file_string++;
		}
		if (char_count < 20 || (*file_string && *file_string != '\n'))
			return (-1);
		tetri_count++;
		if (*file_string)
			file_string++;
	}
	if (tetri_count > 26)
		return (-1);
	return (tetri_count);
}
