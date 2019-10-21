/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:04:21 by idsy              #+#    #+#             */
/*   Updated: 2019/10/11 16:25:48 by idsy             ###   ########.fr       */
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

static	int	check_line(char **file_string, int *hash_count)
{
	int	char_nb;

	char_nb = 0;
	while (*file_string != '\n' && *file_string)
	{
		if (*file_string == '#')
			hash_count++;
		if (*file_string != '.' && *file_string != '#')
			return (-1);
		char_nb++;
		file_string++;
	}
	if (char_nb != 4 || *file_string != '\n' || hash_count > 4)
		return (-1);
	if (*file_string)
		file_string++;
	return (hash_count);	
}

/*
** Check_tetri: A tetrimino should have 4 lines with no more than 4 hashs
** if there is a following tetriminos, it shoulb be separated by a '\n'
*/

static	int	check_tetri(char *file_string)
{
	int	hash_count;
	int	line_count;

	hash_count = 0;
	line_count = 0;
	while (*file_string && *file_string != '\n')
	{
		if (check_line(&file_string,&hash_count) == -1)
			return (-1);
		line_count++;
	}
	if (line_count != 4 || hash_count != 4)
		return (-1);
	if (*file_string == '\n')
		return (check_tetri(*(file_string+1))); 
	return (0);
}

/*
** To check the format is the equivalent to say that you check the fact that
** all the hashs they contain are linked between themselves.
** which means that if there is an hash you should check:
** - if it's the first one -> just find another one
** - if it's not te first one you should check above and at the left the hash
** - if one of the the rules, there is an error in the inupt
*/

static	int	check_link_format(char *file_string)
{
	int	hash_count;
	int	total_chars;

	hash_count = 0;
	total_chars = 0;
	while (hash_count < 3)
	{
		if (file_string[total_chars] == '#')
		{
			if (file_string[(total_chars + 5) % 20] != '#' 
			&& file_string[(total_chars + 1) % 20] != '#')
					return (-1);
			else
				hash_count++;		
		}
		total_chars++;
	}
	if (file_string[20] != '\0')
		return (check_link_format(*(file_string + 20)));
	return (0);
}

/*
**	check_space_and_number checks if yhere is indeed less than 26 tetris
**	and if there is indeed tetris, that they are well spaced between themselves
*/

static	int	check_space_and_number(char *file_string)
{
	int	char_count;
	int	tetri_count;

	tetri_count = 0;
	while (*file_string && tetri_count < 28)
	{
		char_count = 0;
		while (char_count++ < 20 && *file_string)
			file_string++;
		if (char_count < 20 || (*file_string && *file_string != '\n'))
			return (-1);
		tetri_count++;
	}
	if (tetri_count > 26)
		return (-1);
	return (0);
}

int		check_file_string(char *file_string)
{
	if (check_space_and_number(file_string) || check_tetri(file_string)
	|| check_link_format(file_string))
		return(-1);
	return (0);
}
