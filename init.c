/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:32:15 by carmand           #+#    #+#             */
/*   Updated: 2017/04/25 21:05:30 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

static void		init_hp(t_tetri *god, int len)
{
	int i;

	i = 0;
	god->hp_i = (int*)malloc(sizeof(int) * len);
	god->hp_j = (int*)malloc(sizeof(int) * len);
	if (!god->hp_j || !god->hp_i)
		exit(0);
	while (i < len)
	{
		god->hp_i[i] = -1;
		god->hp_j[i] = -1;
		i++;
	}
}

static void		init_len(t_tetri *god, int len)
{
	god->len = ft_int_2d(len, 2);
	if (!god->len)
		exit(0);
	god->len = def_len(god);
}

static void		init_pos(t_tetri *god, int len)
{
	god->pos = ft_int_3d(len, 4, 2);
	if (!god->pos)
		exit(0);
}

int				init(t_tetri *god)
{
	int l;

	l = 0;
	while (god->tetri[l] != NULL)
		l++;
	init_hp(god, l);
	init_len(god, l);
	init_pos(god, l);
	return (l);
}
