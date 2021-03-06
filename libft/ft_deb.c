/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:35:42 by idsy              #+#    #+#             */
/*   Updated: 2019/08/13 12:20:06 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deb(char *file, int line)
{
	ft_putstr("\033[1;31mFILE : \"");
	ft_putstr(file);
	ft_putstr("\" \033[0m| \033[1;36mLINE : \"");
	ft_putnbr(line);
	ft_putstr("\"\033[0m\n");
}
