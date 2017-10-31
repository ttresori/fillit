/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/03/24 20:47:57 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

static int	check_neighbours(char **tet, int i, int j)
{
	int r;

	r = 0;
	if (i > 0 && tet[i - 1][j] == '#')
		r++;
	if (i < 3 && tet[i + 1][j] == '#')
		r++;
	if (j > 0 && tet[i][j - 1] == '#')
		r++;
	if (j < 3 && tet[i][j + 1] == '#')
		r++;
	return (r);
}

static int	check_tet(char **tet)
{
	int	i;
	int j;
	int	r;

	i = 0;
	r = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tet[i][j] == '#')
				r = r + check_neighbours(tet, i, j);
			j++;
		}
		i++;
	}
	if (r == 6 || r == 8)
		return (1);
	return (0);
}

int			verif_tetri(char ***tetri)
{
	int	i;

	i = 0;
	while (tetri[i] != NULL)
	{
		if ((check_tet(tetri[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}
