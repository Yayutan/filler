/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:41:26 by mchuang           #+#    #+#             */
/*   Updated: 2020/03/02 19:41:27 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			find_pc_dim(t_filler *fr, t_stats *st)
{
	int				r;
	int				c;
	t_pt			mm[2];

	mm[0] = set_pt(INT_MAX, INT_MAX);
	mm[1] = set_pt(INT_MIN, INT_MIN);
	r = 0;
	while (r < fr->p_r)
	{
		////////////
		ft_putendl_fd(fr->pc[r], fr->fd);
		////////////
		c = 0;
		while (c < fr->p_c)
		{
			if (fr->pc[r][c] == '*')
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
	st->num_pc++;

	////////////
	ft_putnbr_fd(st->num_pc, fr->fd);
	ft_putstr_fd(" piece\n", fr->fd);

	ft_putstr_fd("GOT: (", fr->fd);
	ft_putnbr_fd((mm[1].x - mm[0].x + 1), fr->fd);
	ft_putstr_fd(", ", fr->fd);
	ft_putnbr_fd((mm[1].y - mm[0].y + 1), fr->fd);
	ft_putstr_fd(")\n", fr->fd);

	ft_putstr_fd("SUM: (", fr->fd);
	ft_putnbr_fd(st->sum.x, fr->fd);
	ft_putstr_fd(", ", fr->fd);
	ft_putnbr_fd(st->sum.y, fr->fd);
	ft_putstr_fd(") -> ", fr->fd);
	///////////

	st->sum = set_pt(st->sum.x + (mm[1].x - mm[0].x + 1),
		st->sum.y + (mm[1].y - mm[0].y + 1));

	////////////
	ft_putstr_fd("(", fr->fd);
	ft_putnbr_fd(st->sum.x, fr->fd);
	ft_putstr_fd(", ", fr->fd);
	ft_putnbr_fd(st->sum.y, fr->fd);
	ft_putstr_fd(")\n", fr->fd);

	ft_putstr_fd("AVG: (", fr->fd);
	ft_putnbr_fd(st->sum.x / st->num_pc, fr->fd);
	ft_putstr_fd(", ", fr->fd);
	ft_putnbr_fd(st->sum.y / st->num_pc, fr->fd);
	ft_putstr_fd(")\n\n", fr->fd);
	////////////
}


static int			read_map(t_filler *fr)
{
	int				r;
	char			*line;
	char			**pt;

	r = 0;
	if (get_next_line(0, &line) < 0)
		return (-1);
	free(line);
	while (r < fr->m_r)
	{
		if (get_next_line(0, &line) < 0)
			return (-1);
		if (!(pt = ft_strsplit(line, ' ')) || !(fr->map[r] = ft_strdup(pt[1])))
		{
			if (line)
				free(line);
			ft_free_two_d_a((void**)pt);
			return (-1);
		}
		free(line);
		ft_free_two_d_a((void**)pt);
		r++;
	}
	return (0);
}

int					setup_map(t_filler *fr)
{
	char			*line;
	char			**pt;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (-1);
	if (!line || !ft_strcmp(line, "") || !(pt = ft_strsplit(line, ' ')))
	{
		if (line)
			free(line);
		return (-1);
	}
	fr->m_r = ft_atoi(pt[1]);
	fr->m_c = ft_atoi(pt[2]);
	free(line);
	ft_free_two_d_a((void**)pt);
	if (!(fr->map = (char**)ft_memalloc((fr->m_r + 1) * sizeof(char*))))
		return (-1);
	fr->map[fr->m_r] = NULL;
	return (read_map(fr));
}

static int			read_piece(t_filler *fr, t_stats *st)
{
	int				r;
	char			*line;

	r = 0;
	while (r < fr->p_r)
	{
		if (get_next_line(0, &line) < 0)
			return (-1);
		if (!(fr->pc[r] = ft_strdup(line)))
		{
			free(line);
			return (-1);
		}
		free(line);
		r++;
	}
	find_pc_dim(fr, st);
	return (0);
}

int					setup_piece(t_filler *fr, t_stats *st)
{
	char			*line;
	char			**pt;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (-1);
	if (!(pt = ft_strsplit(line, ' ')))
	{
		free(line);
		return (-1);
	}
	fr->p_r = ft_atoi(pt[1]);
	fr->p_c = ft_atoi(pt[2]);
	free(line);
	ft_free_two_d_a((void**)pt);
	if (!(fr->pc = (char**)ft_memalloc((fr->p_r + 1) * sizeof(char*))))
		return (-1);
	fr->pc[fr->p_r] = NULL;
	return (read_piece(fr, st));
}
