/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:24:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/22 13:44:48 by jle-quer         ###   ########.fr       */
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
int					add_elem(t_stack *stack, long nbr);
void				free_list(t_stack *stack);
int					parse_stack(int argc, char **argv, int i);
void				print_stack(t_stack *stack);
int					rotate(t_stack *stack, int reverse);
int					swap(t_stack *stack);
int					push(t_stack *a, t_stack *b);

#endif
