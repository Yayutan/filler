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

	//////// <READ MAP>
	r = 0;
	get_next_line(0, &line);
	free(line);
	while (r < fr->m_r)
	{
		if (get_next_line(0, &line) < 0)				
			break;
		if (!(pt = ft_strsplit(line, ' ')) || !(fr->map[r] = ft_strdup(pt[1])))
		{
			free(line);
			// ft_free_two_d_a(pt); // TODO
			return (-1);
		}
		// ft_putendl_fd(line, fr->fd);
		free(line);
		// ft_putendl_fd(fr->map[r], fr->fd);
		///////
		// ft_printf("%s\n", fr->map[r]);
		///////
		r++;
	}
	return (0);
}

int					setup_py_map(t_filler *fr)
{
	char			*line;
	char			**pt;

	///////// <READ MAP DIM>	
	// if (get_next_line(0, &line) < 0)
			// return (-1);
	// get_next_line(0, &line);
	ft_printf("5 5\n");
	return (1);
	if (!(pt = ft_strsplit(line, ' ')))
	{
		free(line);
		return (-1);
	}

	fr->m_r = ft_atoi(pt[1]);
	fr->m_c = ft_atoi(pt[2]);
	////////
	// ft_printf("M:(%d, %d)\n", fr->m_r, fr->m_c);
	////////
	free(line);
	// ft_free_two_d_a(pt); // TODO
	if (!(fr->map = (char**)ft_memalloc((fr->m_r + 1) * sizeof(char*))))
		return (-1);
	fr->map[fr->m_r] = NULL;
	return (read_map(fr));
}

int			setup_piece(t_filler *fr)
{
	int				r;
	char			*line;
	char			**pt;

	//////// <READ PIECE DIM>
	if (get_next_line(0, &line) < 0)
			return (-1);
	if (!(pt = ft_strsplit(line, ' ')))
	{
		free(line);
		return (-1);
	}
	fr->p_r = ft_atoi(pt[1]);
	fr->p_c = ft_atoi(pt[2]);
	////////
	// ft_printf("P:(%d, %d)\n", fr->p_r, fr->p_c);
	////////
	free(line);
	// ft_free_two_d_a(pt); // TODO	
	if (!(fr->pc = (char**)ft_memalloc((fr->p_r + 1) * sizeof(char*))))
		return (-1);
	fr->pc[fr->p_r] = NULL;
	//////// <READ PIECE>
	r = 0;
	while (r < fr->p_r)
	{
		if (get_next_line(0, &line) < 0)				
			break;
		if (!(fr->pc[r] = ft_strdup(line)))
		{
			free(line);
			return (-1);
		}
		// ft_putendl_fd(line, fr->fd);
		free(line);
		// ft_putendl_fd(fr->pc[r], fr->fd);
		///////
		// ft_printf("%s\n", fr->pc[r]);
		///////
		r++;
	}
	return (0);
}



