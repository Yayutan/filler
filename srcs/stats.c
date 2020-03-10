/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
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

int				set_prev_map(t_filler *fr)
{
	int				r;

	if (!fr->map)
		return (1);
	if (!fr->p_map && !(fr->p_map = (char**)ft_memalloc((fr->m_r + 1) * sizeof(char*))))
		return (-1);
	fr->p_map[fr->m_r] = NULL;
	r = 0;
	while (r < fr->m_r)
	{
		if (!fr->p_map[r] && !(fr->p_map[r] = ft_strdup(fr->map[r])))
			return (-1);
		else
			ft_strcpy(fr->p_map[r], fr->map[r]);
		r++;
	}
	return (0);
}

void			set_prev_pt(t_filler *fr, t_stats *st) // add altenative to avg
{
	int				r;
	int				c;
	char			op;
	t_pt			mm[2];

	mm[0] = set_pt(INT_MAX, INT_MAX);
	mm[1] = set_pt(INT_MIN, INT_MIN);
	op = (fr->py == 'O') ? 'X' : 'O';
	//////////
	// ft_putendl_fd("Prev map:", fr->fd);
	//////////
	r = 0;
	while (r < fr->m_r)
	{
		//////////
		// ft_putendl_fd(fr->p_map[r], fr->fd);
		//////////
		c = 0;
		while (c < fr->m_c)
		{
			if (fr->map[r][c] == op && fr->p_map[r][c] == '.')
			{
				mm[0].y = (r < mm[0].y) ? r : mm[0].y;
				mm[1].y = (r > mm[1].y) ? r : mm[1].y;
				mm[0].x = (c < mm[0].x) ? c : mm[0].x;
				mm[1].x = (c > mm[1].x) ? c : mm[1].x;
			}
			c++;
		}
		r++;
	}
	// st->num_pc++;
	// st->sum = set_pt(st->sum.x + (mm[1].x - mm[0].x + 1),
		// st->sum.y + (mm[1].y - mm[0].y + 1));  // add altenative to avg

	st->pre = set_pt((mm[0].x + mm[1].x) / 2, (mm[0].y + mm[1].y) / 2);
	////////////
	// ft_putstr_fd("GOT OP: \n X:", fr->fd);
	// ft_putnbr_fd(mm[0].x, fr->fd);
	// ft_putstr_fd(" ~ ", fr->fd);
	// ft_putnbr_fd(mm[1].x, fr->fd);
	// ft_putstr_fd("\tY:", fr->fd);
	// ft_putnbr_fd(mm[0].y, fr->fd);
	// ft_putstr_fd(" ~ ", fr->fd);
	// ft_putnbr_fd(mm[1].y, fr->fd);
	// ft_putstr_fd("\n", fr->fd);

	// ft_putstr_fd("PT: (", fr->fd);
	// ft_putnbr_fd(st->pre.x, fr->fd);
	// ft_putstr_fd(", ", fr->fd);
	// ft_putnbr_fd(st->pre.y, fr->fd);
	// ft_putstr_fd(")\n\n", fr->fd);
	////////////
}

int					update_pts(t_filler *fr, t_stats *st)
{
	int				r;
	int				c;
	char			op;
	t_pt			*new_pt;

	op = (fr->py == 'O') ? 'X' : 'O';
	r = 0;
	while (r < fr->m_r)
	{
		c = 0;
		while (c < fr->m_c)
		{
			if (fr->map[r][c] == fr->py || fr->map[r][c] == op)
				if (!fr->p_map || fr->p_map[r][c] == '.')
				{
					if (!(new_pt = (t_pt*)ft_memalloc(sizeof(t_pt))))
						return (-1);
					*new_pt = set_pt(c, r);
					if (fr->map[r][c] == fr->py)
					{
						ft_putendl_fd("PUT ME", 2);
						ft_lstadd(&st->my_pt, ft_lstnew((void*)new_pt, sizeof(t_pt)));
					}
					else
					{
						ft_putendl_fd("PUT OP", 2);
						ft_lstadd(&st->op_pt, ft_lstnew((void*)new_pt, sizeof(t_pt)));
					}
					free(new_pt);
				}
			c++;
		}
		r++;
	}
	////////
	ft_putstr_fd("Score: ", 2);
	if (fr->py == 'O')
	{
		ft_putstr_fd("O: ", 2);
		if (st->my_pt)
			ft_putnbr_fd((int)ft_lstlen(st->my_pt), 2);
		else
			ft_putnbr_fd(0, 2);
		ft_putstr_fd("\tX: ", 2);
		if (st->op_pt)
			ft_putnbr_fd((int)ft_lstlen(st->op_pt), 2);
		else
			ft_putnbr_fd(0, 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd("O: ", 2);
		if (st->op_pt)
			ft_putnbr_fd((int)ft_lstlen(st->op_pt), 2);
		else
			ft_putnbr_fd(0, 2);
		ft_putstr_fd("\tX: ", 2);
		if (st->my_pt)
			ft_putnbr_fd((int)ft_lstlen(st->my_pt), 2);
		else
			ft_putnbr_fd(0, 2);
		ft_putstr_fd("\n", 2);
	}
	//////
	return (0);
}




