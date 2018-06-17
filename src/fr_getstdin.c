/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_getstdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 19:22:16 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/17 19:16:42 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			fr_getstdin(t_filler *data)
{
	char	*line;
	t_list	*new;
	int		ret;

	if (ft_get_next_line(0, &line) < 0)
		return (-1);
	if (!(new = ft_lstnew(NULL, 0)))
		return (-1);
	new->content = (void*)line;
	data->std = new;
	while ((ret = ft_get_next_line(0, &line)) > 0)
	{
		if (!(new = ft_lstnew(NULL, 0)))
			return (-1);
		if (!ft_strncmp(line, "Piece", 5))
			data->stop = ft_atoi(line + 6);
		data->index = data->stop == 0 ? 0 : data->index + 1;
		new->content = (void*)line;
		ft_lstadd_back(data->std, new);
		if (data->index > data->stop)
			break ;
	}
	if (ret < 0)
		return (-1);
	return (1);
}
