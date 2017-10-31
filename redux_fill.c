/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redux_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/05/08 19:43:41 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

int	redux_fill(int i, int *j, t_tetri *god, int *r)
{
	if (god->tab_r[i][*j] == '.')
	{
		if (check(god->tab_r, god->tetri[god->it], i, *j) == 1)
		{
			god->tab_r = fill(god, i, *j, god->letter);
			r[0] = 1;
			god->hp_i[god->it] = i;
			god->hp_j[god->it] = *j;
			r[1] = 0;
			return (1);
		}
	}
	*j = *j + 1;
	return (0);
}
