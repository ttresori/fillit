/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/05/08 19:42:16 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

static int	min_square(int n)
{
	int i;
	int	j;
	int	r;

	r = 1;
	i = 3;
	j = 1;
	while (r < n)
	{
		r = r + i;
		i = i + 2;
		j++;
	}
	return (j);
}

int			**def_len(t_tetri *god)
{
	int i;

	i = 0;
	while (god->tetri[i] != NULL)
	{
		god->len[i] = def_one_len(god->tetri[i], god->len[i]);
		i++;
	}
	return (god->len);
}

int			*def_one_len(char **piece, int *len)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] != '.')
			{
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
	len[0] = k;
	len[1] = def_one_len_2d(piece);
	return (len);
}

int			def_one_len_2d(char **piece)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[j][i] != '.')
			{
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (k);
}

void		algo_tetri(t_tetri *god)
{
	int		i;
	int		j;
	int		r;

	i = init(god);
	r = i;
	i = min_square(i * 4);
	god->tab_r = NULL;
	while (god->tab_r == NULL)
	{
		god->lt = i;
		god->tab_r = ft_mem_char_2d(i, i, '.');
		if (!god->tab_r)
			exit(0);
		find_order(r, god);
		j = 0;
		while (god->tab_r[j] != NULL)
		{
			free(god->tab_r[j]);
			j++;
		}
		free(god->tab_r);
		god->tab_r = NULL;
		i++;
	}
}
