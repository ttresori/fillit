/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:44:33 by carmand           #+#    #+#             */
/*   Updated: 2017/04/25 20:53:43 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

void		affiche_tab_r(char **tab_r)
{
	int j;

	j = 0;
	while (tab_r[j] != NULL)
	{
		ft_putendl(tab_r[j]);
		j++;
	}
}

static int	redux_main(char **v)
{
	int		fd;
	t_list	*bgn;
	t_tetri	*god;

	fd = open(v[1], O_RDONLY);
	if (fd == -1)
		ft_putendl("error");
	else
	{
		bgn = def_list(fd);
		if (!bgn)
			return (0);
		god = (t_tetri*)malloc(sizeof(t_tetri));
		close(fd);
		god->tetri = def_tetri(bgn);
		if (!god->tetri)
		{
			ft_putendl("error");
			return (0);
		}
		algo_tetri(god);
	}
	return (1);
}

int			main(int a, char **v)
{
	if (a != 2)
		ft_putendl("error");
	else
		redux_main(v);
	return (0);
}
