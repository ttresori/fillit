/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/04/25 23:54:48 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

static char		**create_tetri(void)
{
	char	**tet;
	int		i;

	i = 0;
	tet = (char**)malloc(sizeof(char*) * 4);
	if (!tet)
		return (NULL);
	while (i < 4)
	{
		tet[i] = (char*)malloc(sizeof(char) * 4);
		if (tet[i] == NULL)
			return (NULL);
		i++;
	}
	return (tet);
}

static char		***create_list_tetri(int size)
{
	char	***tetri;
	int		i;

	i = 0;
	tetri = (char***)malloc(sizeof(char**) * (size + 1));
	if (!tetri)
		return (NULL);
	while (i < size)
	{
		tetri[i] = create_tetri();
		if (tetri[i] == NULL)
			return (NULL);
		i++;
	}
	return (tetri);
}

static char		***cp_tetri(t_list *bgn, char ***tetri)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (tetri[i] != NULL)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				tetri[i][j][k] = ((char*)bgn->content)[0];
				bgn = bgn->next;
				k++;
			}
			bgn = bgn->next;
			j++;
		}
		i++;
		if (tetri[i] != NULL)
			bgn = bgn->next;
	}
	return (tetri);
}

static char		***alpha_tetri(char ***tetri)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (tetri[i] != NULL)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (tetri[i][j][k] == '#')
					tetri[i][j][k] = 'A' + i;
				k++;
			}
			j++;
		}
		i++;
	}
	return (tetri);
}

char			***def_tetri(t_list *bgn)
{
	char	***tetri;
	int		size;

	size = 0;
	if ((verif_list(bgn, &size)) == 0)
		return (NULL);
	tetri = create_list_tetri(size);
	tetri = cp_tetri(bgn, tetri);
	if (!tetri)
		return (NULL);
	tetri = cp_tetri(bgn, tetri);
	if (verif_tetri(tetri) == 0)
		return (NULL);
	tetri = alpha_tetri(tetri);
	return (tetri);
}
