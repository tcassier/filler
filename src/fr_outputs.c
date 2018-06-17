/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_outputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:05:29 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/17 18:56:05 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	fr_check_position(t_filler *data, int x, int y)
{
	int		x_piece;
	int		y_piece;
	int		nb_circle;

	x_piece = data->width_top_x;
	nb_circle = 0;
	while (x_piece <= data->width_bot_x)
	{
		y_piece = data->width_left_y;
		while (y_piece <= data->width_right_y)
		{
			if (data->map[x + x_piece][y + y_piece] == data->player &&
			data->piece[x_piece][y_piece] == '*')
				nb_circle++;
			if (nb_circle > 1 || (data->map[x + x_piece][y + y_piece]
			== data->enemy && data->piece[x_piece][y_piece] == '*'))
				return (-1);
			y_piece++;
		}
		x_piece++;
	}
	if (nb_circle == 1)
		return (0);
	return (-1);
}

t_pos		*fr_outputs(t_filler *data)
{
	t_pos	*pos;
	int		x;
	int		y;

	pos = NULL;
	x = 0 - data->width_top_x;
	while (x < data->map_x - data->width_bot_x)
	{
		y = 0 - data->width_left_y;
		while (y < data->map_y - data->width_right_y)
		{
			if (!fr_check_position(data, x, y))
				if (fr_pos_link_add(&pos, x, y) < 0)
					return (pos);
			y++;
		}
		x++;
	}
	return (pos);
}
