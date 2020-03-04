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

static t_filler		init_filler(void)
{
	t_filler		fr;

	fr.m_r = -1;
	fr.m_c = -1;
	fr.map = NULL;
	fr.py = 0;
	fr.p_r = -1;
	fr.p_c = -1;
	fr.pc = NULL;
	return (fr);
}

int					main(void)
{
	t_filler		fr;
	char			*line;

	fr = init_filler();
	get_next_line(0, &line);
	fr.py = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	free(line);
	while(1)
	{
		if (setup_map(&fr) < 0 || setup_piece(&fr) < 0)
			break;
		// update_stats(&fr); // count p1p2 piece...
		put_piece(&fr);
	}
	return (0);
}
