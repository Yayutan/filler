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

static void			find_available(t_filler *fr)
{
	t_pt			cur;

	fr->av_ct = 0;
	if (!fr->avail)
		if (!(fr->avail = (t_option*)ft_memalloc(fr->m_r * fr->m_c * sizeof(t_option))))
			return ;
	cur.y = -1 * fr->p_r;
	while (cur.y < fr->m_r + fr->p_r)
	{
		cur.x = -1 * fr->p_c;
		while (cur.x < fr->m_c + fr->p_c)
		{
			if (try_piece(fr, cur))
			{
				fr->avail[fr->av_ct].pt.x = cur.x;
				fr->avail[fr->av_ct].pt.y = cur.y;
				fr->avail[fr->av_ct].score = 0;
				fr->av_ct++;
			}
			cur.x++;
		}
		cur.y++;
	}
}

void				put_piece(t_filler *fr)
{
	find_available(fr);
	if (!fr->avail || fr->av_ct == 0)
		ft_printf("-1 -1\n");
	else
		ft_printf("%d %d\n", fr->avail[0].pt.y % fr->m_r, fr->avail[0].pt.x % fr->m_c);
}
