/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opening.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:47:17 by idsy              #+#    #+#             */
/*   Updated: 2019/11/21 15:20:53 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Open and get file open a file and puts whatever text it contains in a buffer
** called file_string. This is the string that will be analised.
** Keep in mind that You are limited to only 1 argument and 1 file
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
