/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/05/08 19:42:44 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

static char	**erase(char **tab_r, int letter, int ***pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tab_r[pos[letter][i][0]][pos[letter][i][1]] = '.';
		i++;
	}
	return (tab_r);
}

static int	verif_stay(int *stay)
{
	int	i;

	i = 0;
	while (stay[i] != -2)
	{
		if (stay[i] != -1)
			return (0);
		i++;
	}
	return (1);
}

static void	inside_you_kidding(t_tetri *god, int *r, int i, int step)
{
	while (r[1] == 0)
	{
		god->it = i;
		god->letter = step;
		god->tab_r = fill_one(r, god);
		god->stay[i] = -1;
		if (r[0] == 1)
		{
			if (verif_stay(god->stay))
			{
				affiche_tab_r(god->tab_r);
				free_fillit(god);
				exit(0);
			}
			else
				you_kidding(god, (step + 1));
			god->tab_r = erase(god->tab_r, step, god->pos);
		}
		else
			r[0] = 1;
	}
}

void		you_kidding(t_tetri *god, int step)
{
	int i;
	int	r[2];

	i = 0;
	r[0] = 1;
	r[1] = 0;
	while (god->stay[i] != -2)
	{
		if (god->stay[i] != -1)
		{
			inside_you_kidding(god, r, i, step);
			god->stay[i] = i;
			god->hp_i[i] = -1;
			god->hp_j[i] = -1;
		}
		i++;
	}
}

int			find_order(int nb_p, t_tetri *god)
{
	int	i;

	god->stay = (int*)malloc(sizeof(int) * (nb_p + 1));
	if (!god->stay)
		return (0);
	i = 0;
	while (i < nb_p)
	{
		god->stay[i] = i;
		i++;
	}
	god->stay[i] = -2;
	you_kidding(god, 0);
	free(god->stay);
	return (1);
}
