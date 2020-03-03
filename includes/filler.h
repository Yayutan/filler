/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:10:59 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/28 21:11:00 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>




/////
#include <fcntl.h>

////

typedef struct 			s_filler
{			
	int					m_r;
	int					m_c;
	char				**map;
	char				py;
	int					p_r;
	int					p_c;
	char				**pc;
	int 				fd; /// for debug
}						t_filler;



int					setup_py_map(t_filler *fr);
int					setup_piece(t_filler *fr);

#endif