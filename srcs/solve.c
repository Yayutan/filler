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

int				set_prev(t_filler *fr)
{
	int				r;

	if (!fr->map)
		return (1);
	if (!(fr->p_map = (char**)ft_memalloc((fr->m_r + 1) * sizeof(char*))))
		return (-1);
	fr->p_map[fr->m_r] = NULL;
	r = 0;
	while (r < fr->m_r)
	{
		fr->p_map[r] = ft_strdup(fr->map[r]);
		r++;
	}
	return (0);
}