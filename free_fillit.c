/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:24:03 by carmand           #+#    #+#             */
/*   Updated: 2017/05/08 19:28:43 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

void	free_fillit(t_tetri *god)
{
	int	i;
	int	j;

	i = 0;
	while (god->tetri[i] != NULL)
		i++;
	ft_free_int_3d(god->pos, i, 4);
	ft_free_char_3d(god->tetri, i, 4);
	j = 0;
	while (god->tab_r[j] != NULL)
		j++;
	ft_free_char_2d(god->tab_r, j);
	if (god->stay != NULL)
		free(god->stay);
	ft_free_int_2d(god->len, i);
	if (god->hp_i != NULL)
		free(god->hp_i);
	if (god->hp_j != NULL)
		free(god->hp_j);
	free(god);
}
