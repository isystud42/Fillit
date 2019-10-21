/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:48:32 by idsy              #+#    #+#             */
/*   Updated: 2019/10/11 16:26:08 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** basically opening the file and getting a string out of it while being
** secure and check for any possible error be it in a system call or in
** entry values of the program
*/

static	char	*open_and_get_file(int argc, char **argv)
{
	int		fd;
	char	*file_string;
	int		ret;
	char	*buff[BUFF_SIZE + 1];

	if (argc > 2)
		//error + message
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		//error + message
	if ((ret = read(fd, buff, BUFF_SIZE) > 545))
		//error + message
	buff[ret] = '\0';
	if ((close(fd)) == -1)
		//error + message
	if (!(file_string = ft_strdup(buff)))
		//error + message
	return (file_string);
}

/*
** cut down pieces takes the file string (info from the file) and cuts it down,
** to a table a strings, holding each pieces.
*/

static	char	**cut_down_pieces(char *file_string, int piece_count)
{
	char	**pieces;
	char	*cut_piece;
	int		foo;

	if (!(pieces = (char **)malloc(sizeof(char *) * (piece_count + 1))))
		return (NULL);
	foo = 0;
	while (*file_string && (*file_string != '\n'))
	{
		if (!(pieces[foo] = (char *)malloc(sizeof(char) * 16 + 1)))
			return (NULL);
		pieces[foo] = ft_strdup_until(file_string, '\n');
		pieces[foo][16] = '\n';
		file_string += 17;
	}
	return (pieces);
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
		piece_bits << 4;
	while (!(piece_bits & 0x8000) || !(piece_bits & 0x800)
		|| !(piece_bits & 0x80))
		piece_bits << 1;
	return (piece_bits);
}

/*
** simplify pieces takes the original string of a piece and turn it into
** "compressed" info but changing the support of from string a of 16 chars
** each stored on a byte for a total of 16 bytes, to a unique int storing both
** the placement of each line 4 bits by 4 bits, moving it to absolute position
** and storing the letter of the piece. ALL that on only 2 bytes.
*/

static	long	simplify_piece(char *piece, int name)
{
	long	piece_bits;

	piece_bits = 0;
	while (*piece)
	{
		if (*piece == "#")
			piece_bits += 1;
		piece++;
		if (*piece)
			piece_bits << 1;
	}
	piece_bits = find_absolute_placement(piece_bits);
	piece_bits += (name << 16);
	return (piece_bits);
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

int				*parsing_of_the_file(int argc, char **argv)
{
	char	*file_string;
	char	**pieces;
	long	*simplified_pieces;
	int		foo;

	file_string = open_and_get_file(argc, argv);
	if (!(check_file_string(file_string)))
		return (-1);
	pieces = cut_down_pieces(file_string);
	foo = 0;
	while (pieces[foo])
		simplified_pieces[foo] = simplify_piece(pieces[foo], foo++);
	free(file_string);
	ft_deltab(pieces);
	return (simplified_pieces);
}
