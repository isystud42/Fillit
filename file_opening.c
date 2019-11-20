/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opening.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:47:17 by idsy              #+#    #+#             */
/*   Updated: 2019/11/19 17:00:57 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** basically opening the file and getting a string out of it while being
** secure and check for any possible error be it in a system call or in
** entry values of the program
*/

char	*open_and_get_file(int argc, char **argv)
{
	int		fd;
	char	*file_string;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	if (argc > 2)
	{
		ft_putendl("usage : ./fillit <file>.");
		return (NULL);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (((ret = read(fd, buff, BUFF_SIZE)) > 545))
		return (NULL);
	buff[ret] = '\0';
	if ((close(fd)) == -1)
		return (NULL);
	if (!(file_string = ft_strdup((const char *)buff)))
		return (NULL);
	return (file_string);
}
