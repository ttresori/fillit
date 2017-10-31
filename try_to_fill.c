/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/05/08 19:52:33 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

static int	init_pos(int *it, int *jt, int ip, int jp)
{
	*it = *it - ip;
	*jt = *jt - jp;
	return (1);
}

char		**fill(t_tetri *god, int it, int jt, int letter)
{
	int	ip;
	int	jp;
	int f;
	int i;

	ip = -1;
	f = 0;
	i = 0;
	while (++ip < 4)
	{
		jp = -1;
		while (++jp < 4)
		{
			if (god->tetri[god->it][ip][jp] != '.')
			{
				if (f == 0)
					f = init_pos(&it, &jt, ip, jp);
				god->tab_r[ip + it][jp + jt] = god->tetri[god->it][ip][jp];
				god->pos[letter][i][0] = ip + it;
				god->pos[letter][i][1] = jp + jt;
				i++;
			}
		}
	}
	return (god->tab_r);
}

int			check(char **tab_r, char **piece, int it, int jt)
{
	int	ip;
	int	jp;
	int f;

	ip = 0;
	f = 0;
	while (ip < 4)
	{
		jp = 0;
		while (jp < 4)
		{
			if (piece[ip][jp] != '.')
			{
				if (f == 0)
					f = init_pos(&it, &jt, ip, jp);
				if (!(jp + jt > -1 && tab_r[ip + it][jp + jt] == '.'))
					return (0);
			}
			jp++;
		}
		ip++;
	}
	return (1);
}

static void	init_fill(int *e, int *i, t_tetri *god, int *r)
{
	if (god->hp_i[god->it] != -1)
	{
		*e = 1;
		*i = god->hp_i[god->it];
	}
	else
	{
		*e = 0;
		*i = 0;
	}
	r[0] = 0;
}

char		**fill_one(int *r, t_tetri *god)
{
	int		i;
	int		j;
	int		e;

	init_fill(&e, &i, god, r);
	while (i < (god->lt - god->len[god->it][0] + 1))
	{
		if (e == 1)
		{
			j = god->hp_j[god->it] + 1;
			e = 0;
		}
		else
			j = 0;
		while (j < god->lt)
		{
			if (redux_fill(i, &j, god, r))
				return (god->tab_r);
		}
		i++;
	}
	r[1] = 1;
	return (god->tab_r);
}
