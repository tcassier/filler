/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 03:41:50 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/15 11:25:22 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct		s_pos
{
	int				x;
	int				y;
	struct s_pos	*next;
}					t_pos;

typedef struct		s_filler
{
	char			player;
	char			enemy;
	t_list			*std;

	char			**map;
	char			**prev_map;
	int				map_x;
	int				map_y;

	char			**piece;
	int				piece_x;
	int				piece_y;

	int				width_top_x;
	int				width_bot_x;
	int				width_right_y;
	int				width_left_y;

	t_pos			*pos;
	int				index;
	int				stop;
}					t_filler;

int					fr_getstdin(t_filler *data);
int					fr_parser(t_filler *data);
int					fr_solver(t_filler *data);
int					fr_check(t_filler *data);
void				fr_get_pos(t_filler *data);
int					fr_pos_link_add(t_pos **pos, int x, int y);
void				fr_pos_link_free(t_pos **lst);
t_pos				*fr_outputs(t_filler *data);
void				fr_choose(t_filler *data);
#endif
