/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 05:32:24 by tcassier          #+#    #+#             */
/*   Updated: 2018/07/02 16:32:25 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		fr_fill_map(t_filler *data, t_list *tmp)
{
	int	index;
	int	index_bis;

	if (!(data->map = (char**)ft_memalloc(sizeof(char*) * (data->map_x + 1))))
		return (-1);
	index = 0;
	while (index < data->map_x && tmp)
	{
		if (!((data->map)[index] = ft_strnew(data->map_y)))
			return (-1);
		index_bis = 0;
		while (index_bis < data->map_y && ((char*)tmp->content)[index_bis + 4])
		{
			if (((char*)tmp->content)[index_bis + 4] != '.' &&
			((char*)tmp->content)[index_bis + 4] != 'O' &&
			((char*)tmp->content)[index_bis + 4] != 'X')
				return (-1);
			(data->map)[index][index_bis] =
			((char*)tmp->content)[index_bis + 4];
			index_bis++;
		}
		tmp = tmp->next;
		index++;
	}
	return (1);
}

static void		fr_skip_map(t_filler *data, t_list **tmp)
{
	int			index;

	index = 0;
	while (index < data->map_x && *tmp)
	{
		*tmp = (*tmp)->next;
		index++;
	}
}

static int		fr_get_piece(t_filler *data, t_list *tmp)
{
	int			index;
	int			index_bis;

	if (!(data->piece = (char**)ft_memalloc(sizeof(char*) *
	(data->piece_x + 1))))
		return (-1);
	index = 0;
	while (tmp && index < data->piece_x)
	{
		if (!((data->piece)[index] = ft_strnew(data->piece_y)))
			return (-1);
		index_bis = 0;
		while (index_bis < data->piece_y && ((char*)tmp->content)[index_bis])
		{
			if (((char*)tmp->content)[index_bis] != '.' &&
			((char*)tmp->content)[index_bis] != '*')
				return (-1);
			(data->piece)[index][index_bis] = ((char*)tmp->content)[index_bis];
			index_bis++;
		}
		tmp = tmp->next;
		index++;
	}
	return (1);
}

static int		fr_fill_piece(t_filler *data, t_list *tmp)
{
	int			index;

	index = 6;
	if (!tmp || !tmp->content || ft_strlen((char*)tmp->content) < 5)
		return (-1);
	if (!ft_isdigit(((char*)tmp->content)[index]))
		return (-1);
	data->piece_x = ft_atoi(&(((char*)tmp->content)[index]));
	while (ft_isdigit(((char*)tmp->content)[index]) &&
	((char*)tmp->content)[index])
		index++;
	data->piece_y = ft_atoi(&(((char*)tmp->content)[index]));
	if (data->piece_y <= 0 || data->piece_y >= 100 || data->piece_x <= 0 ||
	data->piece_x >= 100)
		return (-1);
	tmp = tmp->next;
	if (fr_get_piece(data, tmp) < 0)
		return (-1);
	return (1);
}

int				fr_parser(t_filler *data)
{
	t_list	*tmp;
	int		index;

	tmp = data->std;
	index = 8;
	if (!tmp || !tmp->content || ft_strlen((char*)tmp->content) < 8)
		return (-1);
	data->map_x = ft_atoi(&(((char*)tmp->content)[index]));
	while (ft_isdigit(((char*)tmp->content)[index]) &&
	((char*)tmp->content)[index])
		index++;
	data->map_y = ft_atoi(&(((char*)tmp->content)[index]));
	if (data->map_y <= 0 || data->map_y >= 101 || data->map_x <= 0 ||
	data->map_x >= 101)
		return (-1);
	tmp = tmp->next;
	if (tmp)
		tmp = tmp->next;
	if (fr_fill_map(data, tmp) < 0)
		return (-1);
	fr_skip_map(data, &tmp);
	if (fr_fill_piece(data, tmp) < 0)
		return (-1);
	return (1);
}
