/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:12:27 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/28 21:12:29 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pt				set_pt(int x, int y)
{
	t_pt			ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

static void			clean_map_pc(t_filler *fr, t_stats *st)
{
	// if (fr->p_map)
	// 	ft_free_two_d_a((void**)fr->p_map);
	if (fr->map)
		ft_free_two_d_a((void**)fr->map);
	if (fr->pc)
		ft_free_two_d_a((void**)fr->pc);
	if (fr->avail)
		free(fr->avail);
	// fr->p_map = NULL;
	fr->map = NULL;
	fr->pc = NULL;
	fr->avail = NULL;
	st->ppre = set_pt(st->pre.x, st->pre.y);
	st->pre = set_pt(-1, -1);
	st->near = set_pt(-1, -1);	
}

static void		init_filler_st(t_filler *fr, t_stats *st)
{
	fr->m_r = -1;
	fr->m_c = -1;
	fr->p_map = NULL;
	fr->map = NULL;	
	fr->py = 0;
	fr->p_r = -1;
	fr->p_c = -1;
	fr->pc = NULL;
	fr->avail = NULL;
	st->pre = set_pt(-1, -1);
	st->ppre = set_pt(-1, -1);
	st->near = set_pt(-1, -1);
	st->sum = set_pt(0, 0);
	st->num_pc = 0;

	/////////
	fr->fd = open("log", O_RDWR | O_TRUNC, 644); // remove
	/////////
}

int					main(void)
{
	t_filler		fr;
	t_stats			st;
	char			*line;

	init_filler_st(&fr, &st);
	get_next_line(0, &line);
	fr.py = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	free(line);
	while(1)
	{
		if (setup_map(&fr) < 0 || setup_piece(&fr, &st) < 0)
			break;
		// update_stats(&fr, &st);
		if (fr.p_map)
			prev_pt(&fr, &st);
		put_piece(&fr);
		if (set_prev(&fr) < 0)
			break;
		clean_map_pc(&fr, &st);
	}
	clean_map_pc(&fr, &st);

	//////
	close(fr.fd);
	/////

	return (0);
}
