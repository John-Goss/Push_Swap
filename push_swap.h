/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:24:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/29 14:29:43 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define RED "\x1b[31m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RST "\x1b[0m"

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
int	g_opt_r;
int	g_opt_c;
int	g_opt_v;

int					parse_opt(int ac, char **argv);
int					parse_error(int error_code);
int					add_elem(t_stack *stack, long nbr);
void				free_list(t_stack *stack);
void				swap_stack(t_stack *a);
int					parse_stack(int argc, char **argv, int i);
int					print_stack(t_stack *stack);
int					rotate(t_stack *stack, int reverse);
int					swap(t_stack *stack);
int					push(t_stack *a, t_stack *b);
int					sort_stack(t_stack *a, t_stack *b);
int					is_sort(t_stack *a);
t_elem				*find_min(t_stack *a);

#endif
