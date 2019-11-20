/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:48:32 by idsy              #+#    #+#             */
/*   Updated: 2019/11/20 14:24:36 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short			piece_counter(char *file_string)
{
	short	file_string_len;

	file_string_len = ft_strlen(file_string);
	return ((file_string_len / 21) + 1);
}

/*
** to find the "absolute placement" of a piece, you need to find the place the
** most to the up and left corner.
**
** in order to do that, you identify the # the most to the left and get to the
** left most extreme position he could get and get the empty line off of the top
*/

static	long	find_absolute_placement(long piece_bits)
{
	while (piece_bits < 0x1000)
		piece_bits <<= 4;
	while (!(piece_bits & 0x8000) && !(piece_bits & 0x800)
		&& !(piece_bits & 0x80))
		piece_bits <<= 1;
	return (piece_bits);
}

/*
** simplify pieces takes the original string of a piece and turn it into
** "compressed" info but changing the support of from string a of 16 chars
** each stored on a byte for a total of 16 bytes, to a unique int storing both
** the placement of each line 4 bits by 4 bits, moving it to absolute position
** and storing the letter of the piece. ALL that on only 2 bytes.
*/

static	long	*simplify_piece(char *file_string, int piece_count, long *simplified_pieces)
{
	int foo;

	foo = 0;
	ft_bzero(simplified_pieces, (piece_count + 1) * sizeof(long));
	while (*file_string)
	{
		if (*file_string == '\n' && (file_string[1] == '\n' || !file_string[1]))
		{
			file_string += 2;
			simplified_pieces[foo] = find_absolute_placement(simplified_pieces[foo]);
			simplified_pieces[foo] |= (foo << 16);
			foo++;
			continue ;
		}
		else if (*file_string == '\n')
		{
			file_string++;
			continue ;
		}
		simplified_pieces[foo] <<= 1;
		if (*file_string == '#')
			simplified_pieces[foo] += 1;
		file_string++;
	}
	return (simplified_pieces);
}

int			check_file_string(char *file_string)
{
DEB
	if ((check_space_and_number(file_string)) == -1)
		return (-1);
DEB	
	if (check_tetri(file_string))
		return (-1);	
DEB	
	if (check_hash_links_format(file_string))
		return (-1);	
DEB	
	return (0);
}

/*
** parsing of the file basically does what the name saying it does. Come on
** i know you are not that dense.
**
** Basically, it;s the main function of parsing that calls all the other sub-ft
** opening, reading and checking the entry file and cutting it down to pieces
** (pun intended)
** returning a table of long ints containing the simplified version
** of all the pieces.
*/

long			*parsing_of_the_file(int argc, char **argv)
{
	char	*file_string;
	long	*simplified_pieces;
	short	piece_count;

	if (!(file_string = open_and_get_file(argc, argv)))
	{
		return (NULL);
	} 
	if (check_file_string(file_string))
	{
		ft_putendl("error");
		return (NULL);
	}
	piece_count = piece_counter(file_string);
	if (!(simplified_pieces = (long *)malloc(sizeof(long) * piece_count + 1)))
		return (NULL);
	simplify_piece(file_string, piece_count, simplified_pieces);	
	free(file_string);
	return (simplified_pieces);
}
