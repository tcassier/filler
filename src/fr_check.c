/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:23:57 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/17 18:55:48 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		fr_check_piece(t_filler *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->piece_x && data->piece[x])
	{
		y = 0;
		while (y < data->piece_y && data->piece[x][y])
		{
			if (data->piece[x][y] != '.' && data->piece[x][y] != '*')
				return (-1);
			y++;
		}
		if (y != data->piece_y)
			return (-1);
		x++;
	}
	if (x != data->piece_x)
		return (-1);
	return (1);
}

int				fr_check(t_filler *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map_x && data->map[x])
	{
		y = 0;
		while (y < data->map_y && data->map[x][y])
		{
			if (data->map[x][y] != '.' && data->map[x][y] != 'O'
			&& data->map[x][y] != 'X')
				return (-1);
			y++;
		}
		if (y != data->map_y)
			return (-1);
		x++;
	}
	if (x != data->map_x)
		return (-1);
	if (fr_check_piece(data) < 0)
		return (-1);
	return (1);
}
