/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:12:06 by mchuang           #+#    #+#             */
/*   Updated: 2020/03/03 20:12:17 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			try_piece(t_filler *fr, t_pt st)
{
	t_pt			p_cur;
	int				ovl;

	p_cur.y = 0;
	ovl = 0;
	while (p_cur.y < fr->p_r)
	{
		p_cur.x = 0;
		while (p_cur.x < fr->p_c)
		{
			if (fr->pc[p_cur.y][p_cur.x] == '*')
			{
				if (fr->map[(st.y + p_cur.y + fr->m_r) % fr->m_r][(st.x + p_cur.x + fr->m_c) % fr->m_c] == fr->py ||
					fr->map[(st.y + p_cur.y + fr->m_r) % fr->m_r][(st.x + p_cur.x + fr->m_c) % fr->m_c] == fr->py + 32)
					ovl++;
				else if (fr->map[(st.y + p_cur.y + fr->m_r) % fr->m_r][(st.x + p_cur.x + fr->m_c) % fr->m_c] != '.')
					return (0);
			}
			p_cur.x++;
		}
		p_cur.y++;
	}
	return (ovl == 1);
}

static int			find_available(t_filler *fr)
{
	t_pt			cur;
	t_option		*new_op;

	fr->av_ct = 0;
	cur.y = -1 * fr->p_r;
	while (cur.y < fr->m_r + fr->p_r)
	{
		cur.x = -1 * fr->p_c;
		while (cur.x < fr->m_c + fr->p_c)
		{
			if (try_piece(fr, cur))
			{
				if (!(new_op = (t_option*)ft_memalloc(sizeof(t_option))))
					return (-1);
				new_op->pt.x = cur.x;
				new_op->pt.y = cur.y;
				new_op->score = 0;
				ft_lstadd(&fr->avail, ft_lstnew((void*)new_op, sizeof(t_option)));
				free(new_op);
				fr->av_ct++;
			}
			cur.x++;
		}
		cur.y++;
	}
	return (0);
}

void				put_piece(t_filler *fr)
{
	t_pt			res;

	if (find_available(fr) < 0 || !fr->avail || fr->av_ct == 0)
		ft_printf("-1 -1\n");
	else
	{
		ft_putstr_fd("Avail #: ", fr->fd);
		ft_putnbr_fd(fr->av_ct, fr->fd);
		ft_putstr_fd("\n", fr->fd);
		res = ((t_option*)(ft_lstat(fr->avail, fr->av_ct - 1)->content))->pt;
		ft_printf("%d %d\n", res.y % fr->m_r, res.x % fr->m_c);
	}
}
