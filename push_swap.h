/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:24:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/21 15:30:40 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define RED "\x1b[31m"
# define RST "\x1b[0m"

typedef struct		s_opt
{
	int				v;
	int				c;
	int				r;
}					t_opt;

typedef struct		s_elem
{
	int				nbr;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_stack
{
	int				nbr;
	struct s_elem	*first;
	struct s_elem	*last;
}					t_stack;

int	g_op_count;

int					parse_opt(int ac, char **argv);
int					parse_error(int error_code);
int					add_elem(t_stack *stack, int nbr);
void				free_list(t_stack *stack);
int					parse_stack(int argc, char **argv, int i);

#endif
