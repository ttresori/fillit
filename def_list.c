/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/05/08 19:27:33 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

static t_list	*first_list(t_list *bgn, char tmp)
{
	bgn = (t_list*)malloc(sizeof(t_list));
	if (!bgn)
		return (NULL);
	bgn->content = (char*)malloc(sizeof(char*) * 1);
	if (bgn->content == NULL)
		return (NULL);
	((char*)bgn->content)[0] = tmp;
	bgn->content_size = 0;
	bgn->next = NULL;
	return (bgn);
}

static t_list	*add_list(t_list *end, char tmp)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	end->next = new;
	new->content = (char*)malloc(sizeof(char) * 1);
	if (new->content == NULL)
		return (NULL);
	((char*)new->content)[0] = tmp;
	new->content_size = 0;
	new->next = NULL;
	return (new);
}

t_list			*def_list(int fd)
{
	t_list	*bgn;
	t_list	*end;
	char	tmp;

	bgn = NULL;
	if (read(fd, &tmp, 1))
	{
		bgn = first_list(bgn, tmp);
		if (!bgn)
			return (NULL);
	}
	else
	{
		ft_putendl("error");
		return (NULL);
	}
	end = bgn;
	while (read(fd, &tmp, 1))
	{
		end = add_list(end, tmp);
		if (!end)
			return (NULL);
	}
	return (bgn);
}
