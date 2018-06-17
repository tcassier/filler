/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 00:28:20 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/14 04:06:52 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_gnl_free(char **line, t_list **begin_list, int check)
{
	if (!check)
	{
		if (line && *line)
			ft_strdel(line);
		if (*begin_list)
			ft_lstdel(begin_list, &ft_memdel_bis);
	}
	return (check == 0 ? -1 : 1);
}
