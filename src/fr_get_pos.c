/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:22:23 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/17 18:55:54 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	fr_get_pos_right(t_filler *data)
{
	int		x;
	int		y;

	y = data->piece_y - 1;
	while (y >= 0)
	{
		x = data->piece_x - 1;
		while (x >= 0)
		{
			if (data->piece[x][y] == '*')
				return (y);
			x--;
		}
		y--;
	}
	return (0);
}

static int	fr_get_pos_bot(t_filler *data)
{
	int		x;
	int		y;

	x = data->piece_x - 1;
	while (x >= 0)
	{
		y = data->piece_y - 1;
		while (y >= 0)
		{
			if (data->piece[x][y] == '*')
				return (x);
			y--;
		}
		x--;
	}
	return (0);
}

static int	fr_get_pos_left(t_filler *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->piece_y)
	{
		x = 0;
		while (x < data->piece_x)
		{
			if (data->piece[x][y] == '*')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

static int	fr_get_pos_top(t_filler *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < data->piece_x)
	{
		y = 0;
		while (y < data->piece_y)
		{
			if (data->piece[x][y] == '*')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

void		fr_get_pos(t_filler *data)
{
	data->width_top_x = fr_get_pos_top(data);
	data->width_left_y = fr_get_pos_left(data);
	data->width_bot_x = fr_get_pos_bot(data);
	data->width_right_y = fr_get_pos_right(data);
}
