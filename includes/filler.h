/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:10:59 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/28 21:11:00 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

///////
# include <fcntl.h>
# include <unistd.h>
//////


typedef struct		s_pt
{
	int				x;
	int				y;
}					t_pt;

typedef struct 		s_option
{
	t_pt			pt;
	int				score;
}					t_option;

typedef struct 		s_stats
{
	t_pt			pre;
	t_pt			ppre;
	t_pt			near;
	t_pt			sum;
	int				num_pc;
	t_list			*my_pt;
	t_list			*op_pt;
}					t_stats;

typedef struct		s_filler
{
	int				m_r;
	int				m_c;
	char			**p_map;
	char			**map;
	char			py;
	int				p_r;
	int				p_c;
	char			**pc;
	t_list			*avail;
	int				av_ct;
	//////
	int				fd; // log	
	/////
}					t_filler;

int					setup_map(t_filler *fr);
int					setup_piece(t_filler *fr, t_stats *st);
void				put_piece(t_filler *fr);
t_pt				set_pt(int x, int y);
int					set_prev_map(t_filler *fr);
void				set_prev_pt(t_filler *fr, t_stats *st);
int					update_pts(t_filler *fr, t_stats *st);
#endif
