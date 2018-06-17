/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:04:55 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/17 19:18:17 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		fr_free_map(t_filler *data)
{
	int			index;

	index = 0;
	while (index < data->map_x && data->prev_map[index])
	{
		free((data->prev_map)[index]);
		index++;
	}
	free(data->prev_map);
	data->prev_map = NULL;
}

static void		fr_free_piece(t_filler *data)
{
	int			index;

	index = 0;
	while (index < data->piece_x && data->piece[index])
	{
		free((data->piece)[index]);
		index++;
	}
	free(data->piece);
	data->piece = NULL;
}

int				fr_solver(t_filler *data)
{
	if (fr_check(data) < 0)
		return (-1);
	fr_get_pos(data);
	data->pos = fr_outputs(data);
	if (data->pos)
		fr_choose(data);
	else
		return (0);
	if (data->prev_map)
		fr_free_map(data);
	data->prev_map = data->map;
	data->map = NULL;
	fr_free_piece(data);
	fr_pos_link_free(&(data->pos));
	return (1);
}
