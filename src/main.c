/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 03:42:54 by tcassier          #+#    #+#             */
/*   Updated: 2018/07/02 16:37:40 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		fr_get_number(t_filler *data)
{
	char		*line;
	int			index;

	if (ft_get_next_line(0, &line) < 0)
		return (-1);
	index = 0;
	while (line[index] != 'p' && line[index])
		index++;
	if (line[index + 1] == '1')
	{
		data->player = 'O';
		data->enemy = 'X';
	}
	else if (line[index + 1] == '2')
	{
		data->player = 'X';
		data->enemy = 'O';
	}
	else
	{
		free(line);
		return (-1);
	}
	free(line);
	return (1);
}

static void		fr_init(t_filler *data)
{
	data->index = 0;
	data->stop = 0;
}

int				main(void)
{
	t_filler	*data;
	int			ret;

	if (!(data = (t_filler*)ft_memalloc(sizeof(t_filler))))
		return (EXIT_FAILURE);
	if (fr_get_number(data) < 0)
		return (EXIT_FAILURE);
	while (42)
	{
		fr_init(data);
		if (fr_getstdin(data) < 0)
			return (EXIT_FAILURE);
		if (!data->std)
			return (EXIT_FAILURE);
		if (fr_parser(data) < 0)
			return (EXIT_FAILURE);
		if ((ret = fr_solver(data)) < 0)
			return (EXIT_FAILURE);
		if (!ret)
			break ;
		if (data->std)
			ft_lstdel(&(data->std), &ft_memdel_bis);
	}
	ft_putstr("0 0\n");
	return (EXIT_SUCCESS);
}
