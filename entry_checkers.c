/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:04:21 by idsy              #+#    #+#             */
/*   Updated: 2019/11/21 13:38:16 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check_file_string check if the entry is conform to the format it's supposed
** to have, checking those rules out:
** Only one entry argv, Tetriminos are 4x4 sized and separated by '\n'
** Each caracter is either # or . and there should be no more than 4 #
** tetriminos forms should be coherent with no diagonals and contact between #
** never more than 26 tetriminos
*/

/*
** Check_line: A line should have 4 chars and end by \n
** nothing more than # and . Everything else in an error
*/

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
** To check the format is the equivalent to say that you check the fact that
** all the hashs they contain are linked between themselves.
** which means that if there is an hash you should
**	-check were is the first # you find.
**	-execute a nippet that check and count the number of links
**	  -if the number of links is lower than 1, it's wrong
**	  -if the number of links is lower than 2 more than 3 times then it's wrong
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
**	check_space_and_number checks if yhere is indeed less than 26 tetris
**	and if there is indeed tetris, that they are well spaced between themselves
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
