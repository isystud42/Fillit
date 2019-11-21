/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:05:00 by idsy              #+#    #+#             */
/*   Updated: 2019/11/21 13:39:17 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 4096

char	*open_and_get_file(int argc, char **argv);
void	insert_piece(long **grid, long piece, short line, short line_pos);
void	remove_piece(long **grid, long piece, short line, short line_pos);
void	save_piece_pos(long *pieces, short position);
long	*parsing_of_the_file(int argc, char **argv);
long	*generate_grid(short size);
long	*resize_grid(long *grid, short size);
int		find_out_minimal_grid_size(long *pieces);
int		convert_and_display_grid(long *pieces, short grid_size);
int		check_grid_space(long *grid, short piece, short line, short line_pos);
int		check_file_string(char *file_string);
int		fill_it_backtracking(long *grid, short gd_size,
							short position, long *pieces);
int		check_space_and_number(char *file_string);
int		check_hash_links_format(char *file_string);
int		check_hash_links_snippet(char **file_string, int *one_link_count);
int		check_tetri(char *file_string);
int		check_line(char **file_string, int *hash_count);

#endif
