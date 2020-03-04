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

static int			read_piece(t_filler *fr)
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
	return (0);
}

int			setup_piece(t_filler *fr)
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
	return (read_piece(fr));
}
