/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_pos_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:09:54 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/15 08:48:24 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fr_pos_link_add(t_pos **pos, int x, int y)
{
	t_pos	*new;
	t_pos	*tmp;

	if (!(new = (t_pos*)ft_memalloc(sizeof(t_pos))))
		return (-1);
	new->x = x;
	new->y = y;
	if (!(*pos))
		*pos = new;
	else
	{
		tmp = *pos;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

void	fr_pos_link_free(t_pos **lst)
{
	if (*lst)
	{
		if ((*lst)->next)
			fr_pos_link_free(&(*lst)->next);
		free(*lst);
		*lst = NULL;
	}
}
