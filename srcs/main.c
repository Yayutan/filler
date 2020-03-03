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
	char			*line;

	fr.m_r = -1;
	fr.m_c = -1;
	fr.map = NULL;
	fr.py = 0;
	fr.p_r = -1;
	fr.p_c = -1;
	fr.pc = NULL;
	// ////
	// fr.fd = open("test.out", O_CREAT | O_RDWR, 0644);
	// ////
	/////////// <Set char>
	get_next_line(0, &line);
	fr.py = (ft_atoi(line + 10) == 1) ? 'o' : 'x';
	free(line);
	return (fr);
}


// int					main(int ac, char **av)
int					main(void)
{
	t_filler		fr;

	fr = init_filler();
	// ft_printf("-5 -5\n"); // can be read
	// setup_py_map(&fr);
	// ft_printf("0 0\n");
	// setup_piece(&fr);
	// ft_printf("10 10\n");
	while(!setup_py_map(&fr) && !setup_piece(&fr))
	{
		
	}
	
	// put pc
	// close(fr.fd);

	return (0);
}



// char			*line;
// char			**parts;
// int				m_x;
// int				m_y;
// int				r;
// int				c;
// char			sym;


// 	int fd = open("test.out", O_CREAT | O_RDWR, 0644);
// 	parts = NULL;
// /////////// <Set char>
// 	if (get_next_line(0, &line) < 0)
// 		return (-1);
// 	// ft_putendl_fd(line, fd);
// 	parts = ft_strsplit(line, ' ');
// 	sym = (ft_atoi(parts[2] + 1) == 1) ? 'o' : 'x';

// ///////// <READ MAP DIM>
// 		if (get_next_line(0, &line) < 0)
// 			return (-1);
// 		// ft_putendl_fd(line, fd);		
// 		parts = ft_strsplit(line, ' ');
// 		m_y	 = ft_atoi(parts[1]);
// 		m_x = ft_atoi(parts[2]);

// ///////// <FIND POS>
// 		r = 0;
// 		while (1)
// 		{
// 			if (get_next_line(0, &line) < 0)				
// 				break;
// 			// ft_putendl_fd(line, fd);			
// 			if (!ft_isdigit(line[0]))
// 			{
// 				if (r == 0)
// 					continue ;
// 				else
// 					return (-1); 
// 			}
// 			parts = ft_strsplit(line, ' ');

// 			c = (ft_strchr(parts[1], sym - 32)) ? ft_strchr(parts[1], sym - 32) - parts[1] : -1;
// 			if(c > 0)
// 				ft_printf("%d %d\n", r, c);
// 			// ft_putnbr_fd(r, fd);
// 			// ft_putchar_fd(' ', fd);
// 			// ft_putnbr_fd(c, fd);
// 			// ft_putchar_fd('\n', fd);
// 			r++;

// 		}
	// close(fd);


