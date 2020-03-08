/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:24:13 by mchuang           #+#    #+#             */
/*   Updated: 2020/03/07 18:24:25 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					dist(t_pt p1, t_pt p2)
{
	return ((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

void				update_prev(t_filler *fr, t_stats *st)
{


	// change to compare map?
	(void)fr;
	(void)st;
	// int				r;
	// int				c;
	// char			op;
	// int				found;
	// t_pt			min_max_nr[2];

	// min_max_nr[0] = set_pt(INT_MAX, INT_MAX);
	// min_max_nr[1] = set_pt(INT_MIN, INT_MIN);
	// op = (fr->py == 'O') ? 'x' : 'o';
	// found = 0;
	// r = 0;
	// while (r < fr->m_r)
	// {
	// 	c = 0;
	// 	//////////////////
	// 	ft_putendl_fd(fr->map[r], fr->fd);
	// 	/////////////////
	// 	while (c < fr->m_c)
	// 	{
	// 		if (fr->map[r][c] == op)
	// 		{
	// 			found = 1;
	// 			if (r < min_max_nr[0].y)
	// 				min_max_nr[0].y = r;
	// 			if (r > min_max_nr[1].y)
	// 				min_max_nr[1].y = r;
	// 			if (c < min_max_nr[0].x)
	// 				min_max_nr[0].x = c;
	// 			if (c > min_max_nr[1].x)
	// 				min_max_nr[1].x = c;
	// 		}
	// 		c++;
	// 	}
	// 	r++;
	// }
	// if (!found)
	// {
	// 	ft_putchar_fd(op, fr->fd);
	// 	ft_putendl_fd(" OP not found", fr->fd);
	// 	return ;
	// }
	// st->num_pc++;

	// ////////////
	// ft_putnbr_fd(st->num_pc, fr->fd);
	// ft_putstr_fd(" piece\n", fr->fd);

	// ft_putnbr_fd((min_max_nr[0].x), fr->fd);
	// ft_putstr_fd("~", fr->fd);	
	// ft_putnbr_fd((min_max_nr[1].x), fr->fd);
	// ft_putstr_fd("~", fr->fd);		
	// ft_putnbr_fd((min_max_nr[0].y), fr->fd);
	// ft_putstr_fd("~", fr->fd);	
	// ft_putnbr_fd((min_max_nr[1].y), fr->fd);
	// ft_putstr_fd("\n", fr->fd);	


	// ft_putstr_fd("GOT: (", fr->fd);
	// ft_putnbr_fd((min_max_nr[1].x - min_max_nr[0].x + 1), fr->fd);
	// ft_putstr_fd(", ", fr->fd);
	// ft_putnbr_fd((min_max_nr[1].y - min_max_nr[0].y + 1), fr->fd);
	// ft_putstr_fd(")\n", fr->fd);

	// ft_putstr_fd("SUM: (", fr->fd);
	// ft_putnbr_fd(st->avg.x, fr->fd);
	// ft_putstr_fd(", ", fr->fd);
	// ft_putnbr_fd(st->avg.y, fr->fd);
	// ft_putstr_fd(") -> ", fr->fd);

	// ///////////
	// st->pre = set_pt((min_max_nr[1].x + min_max_nr[0].x) / 2, (min_max_nr[1].y + min_max_nr[0].y) / 2);
	// st->avg = set_pt(st->avg.x + (min_max_nr[1].x - min_max_nr[0].x + 1),
	// 	st->avg.y + (min_max_nr[1].y - min_max_nr[0].y + 1));

	// ////////////
	// ft_putstr_fd("(", fr->fd);
	// ft_putnbr_fd(st->avg.x, fr->fd);
	// ft_putstr_fd(", ", fr->fd);
	// ft_putnbr_fd(st->avg.y, fr->fd);
	// ft_putstr_fd(")\n", fr->fd);

	// ft_putstr_fd("AVG: (", fr->fd);
	// ft_putnbr_fd(st->avg.x / st->num_pc, fr->fd);
	// ft_putstr_fd(", ", fr->fd);
	// ft_putnbr_fd(st->avg.y / st->num_pc, fr->fd);
	// ft_putstr_fd(")\n\n", fr->fd);
	////////////
}