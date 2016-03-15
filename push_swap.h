/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:24:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/15 15:30:57 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

#define RED "\x1b[31m"
#define RST "\x1b[0m"

typedef struct		s_opt
{
	int				v;
	int				c;
	int				r;
}					t_opt;

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int		g_op_count;

int		parse_opt(int ac, char **argv);
int		parse_error(void);

#endif
