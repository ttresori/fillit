/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fillit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:25:15 by carmand           #+#    #+#             */
/*   Updated: 2017/09/30 19:50:18 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FILLIT_H
# define LIB_FILLIT_H

# include "../libft/libft.h"

# include <fcntl.h>

typedef struct	s_tetri
{
	int		***pos;
	char	***tetri;
	char	**tab_r;
	int		*stay;
	int		**len;
	int		it;
	int		lt;
	int		*hp_i;
	int		*hp_j;
	int		letter;
}				t_tetri;

void			affiche_tab_r(char **tab_r);
int				check(char **tab_r, char **piece, int i_t, int j_t);
t_list			*def_list(int fd);
char			**fill(t_tetri *god, int i_t, int j_t, int letter);
char			***def_tetri(t_list *bgn);
void			algo_tetri(t_tetri *god);
char			**fill_one(int *r, t_tetri *god);
int				verif_list(t_list *bgn, int *size);
int				verif_tetri(char ***tetri);
int				find_order(int nb_p, t_tetri *god);
void			you_kidding(t_tetri *god, int step);
int				init(t_tetri *god);
int				**def_len(t_tetri *god);
int				*def_one_len(char **piece, int *len);
int				def_one_len_2d(char **piece);
int				redux_fill(int i, int *j, t_tetri *god, int *r);
void			free_fillit(t_tetri *god);

#endif
