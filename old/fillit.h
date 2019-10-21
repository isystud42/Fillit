/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:17:35 by mbouanik          #+#    #+#             */
/*   Updated: 2016/12/22 19:59:40 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 1000

char				*ft_open(int argc, char **argv);
int					ft_cp(int argc, char **argv);
int					ft_verifchar(int argc, char **argv);
int					ft_verifgrille(int argc, char **argv);
void				ft_place_it_binary(int **grid, int position,
					int size, unsigned long tetri);
t_bool				ft_check_place_binary(int **grid, int position,
							int size, unsigned long tetri);
int					*ft_gensuite(int ac, char **av, int z);
int					ft_nbchar(int ac, char **av);
int					ft_regrouptest(int ac, char **av);
char				***ft_tabtabtabcreat(int ac, char **av);
char				***ft_filltab(char ***tab3d, char *buf, int a, int b);
int					ft_verifpiece(char ***tab, int a, int b);
char				***ft_oktab(int ac, char **av);
int					ft_error(int x);
unsigned long		ft_binary(char **tab_tetri, int i, int j);
void				ft_print_grid(int **grid, int size);
int					**ft_new_grid(int **old_grid, int size);
void				ft_remove_it_binary(int **grid, int position,
					int size, unsigned long tetri);
unsigned long		ft_name(int c, unsigned long binary);

#endif
