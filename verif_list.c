/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/01/11 03:41:51 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

static t_list	*check_list(t_list *bgn, int *j, int *k)
{
	int	i;

	i = 0;
	while (bgn && ((char*)bgn->content)[0] != '\n')
	{
		if (((char*)bgn->content)[0] == '.')
			i++;
		else if (((char*)bgn->content)[0] == '#')
		{
			i++;
			*j = *j + 1;
		}
		else
			return (NULL);
		bgn = bgn->next;
	}
	if (!((i == 4 || i == 0) && *j < 5))
		return (NULL);
	if (i == 4)
		*k = *k + 1;
	return (bgn);
}

static int		check_next_tetri(int *j, int *k, int *size, t_list *bgn)
{
	if (*k == 4 && *j == 4)
	{
		*size = *size + 1;
		*j = 0;
		*k = 0;
		if (bgn->next != NULL)
			if (!(bgn->next->next != NULL
			&& ((char*)bgn->next->content)[0] == '\n'
			&& (((char*)bgn->next->next->content)[0] == '.'
			|| ((char*)bgn->next->next->content)[0] == '#')))
				return (0);
	}
	if (*k == 4 && *j != 4)
		return (0);
	return (1);
}

int				verif_list(t_list *bgn, int *size)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	if (!(((char*)bgn->content)[0] == '.' || ((char*)bgn->content)[0] == '#'))
		return (0);
	while (bgn)
	{
		bgn = check_list(bgn, &j, &k);
		if (!bgn)
			return (0);
		if (!(check_next_tetri(&j, &k, size, bgn)))
			return (0);
		bgn = bgn->next;
	}
	if (k == 0)
		return (1);
	return (0);
}
