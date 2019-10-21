/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kind_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 00:47:03 by mbouanik          #+#    #+#             */
/*   Updated: 2016/12/02 21:52:42 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_kind_realloc(void *ptr, size_t size)
{
	char *new_ptr;

	new_ptr = NULL;
	if (ptr != NULL)
	{
		new_ptr = ft_memalloc(size);
		new_ptr = ft_memcpy(new_ptr, ptr, size);
		ptr = new_ptr;
		free(ptr);
		ptr = NULL;
		return (new_ptr);
	}
	else if (ptr == NULL)
		ptr = ft_memalloc(size);
	return (ptr);
}
