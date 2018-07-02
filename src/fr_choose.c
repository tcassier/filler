/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:01:17 by tcassier          #+#    #+#             */
/*   Updated: 2018/07/02 16:44:16 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fr_get_coord_enemy(t_filler *data, int *x, int *y)
{
	*x = 0;
	while (*x < data->map_x)
	{
		*y = 0;
		while (*y < data->map_y)
		{
			if (data->prev_map[*x][*y] == '.' && data->map[*x][*y]
			!= '.' && data->map[*x][*y] != data->player)
				return ;
			(*y)++;
		}
		(*x)++;
	}
}

void		fr_choose(t_filler *data)
{
	int		x;
	int		y;
	t_pos	*tmp;
	t_pos	*get;

	if (data->prev_map)
		fr_get_coord_enemy(data, &x, &y);
	else
	{
		x = 0;
		y = 0;
	}
	tmp = data->pos->next;
	get = data->pos;
	while (tmp)
	{
		if (ft_sqrt((tmp->x - x) * (tmp->x - x) + (tmp->y - y) * (tmp->y - y))
		< ft_sqrt((get->x - x) * (get->x - x) + (get->y - y) * (get->y - y)))
			get = tmp;
		tmp = tmp->next;
	}
	ft_putnbr(get->x);
	ft_putchar(' ');
	ft_putnbr(get->y);
	ft_putchar('\n');
}
