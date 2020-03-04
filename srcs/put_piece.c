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

static int			try_piece(t_filler *fr, t_coor st)
{
	t_coor			p_cur;
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
				if (st.x + p_cur.x >= fr->m_c || st.y + p_cur.y >= fr->m_r)
					return (0);
				if (fr->map[st.y + p_cur.y][st.x + p_cur.x] == fr->py ||
					fr->map[st.y + p_cur.y][st.x + p_cur.x] == fr->py + 32)
					ovl++;
				else if (fr->map[st.y + p_cur.y][st.x + p_cur.x] != '.')
					return (0);
			}
			p_cur.x++;
		}
		p_cur.y++;
	}
	return (ovl == 1);
}

static void			first_available(t_filler *fr)
{
	t_coor			cur;

	cur.y = 0;
	while (cur.y < fr->m_r)
	{
		cur.x = 0;
		while (cur.x < fr->m_c)
		{
			if (try_piece(fr, cur))
			{
				ft_printf("%d %d\n", cur.y, cur.x);
				return ;
			}
			cur.x++;
		}
		cur.y++;
	}
	ft_printf("-1 -1\n");
}

void				put_piece(t_filler *fr)
{
	first_available(fr);
}
