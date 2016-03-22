/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:24:32 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/22 13:19:21 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *stack)
{
	stack->nbr = 0;
	stack->first = NULL;
	stack->last = NULL;
}

int			add_elem(t_stack *stack, int nbr)
{
	t_elem	*elem;

	if (!(elem = (t_elem *)malloc(sizeof(*elem))))
		return (-1);
	elem->nbr = nbr;
	if (stack->nbr == 0)
	{
		elem->next = NULL;
		elem->prev = NULL;
		stack->first = elem;
		stack->last = elem;
	}
	else
	{
		stack->first->prev = elem;
		elem->next = stack->first;
		elem->prev = NULL;
		stack->first = elem;
	}
	stack->nbr += 1;
	return (0);
}

void		free_list(t_stack *stack)
{
	t_elem	*elem;
	t_elem	*next;

	elem = stack->first;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
}

int			parse_stack(int argc, char **argv, int i)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		j;

	init_stack(&stack_a);
	init_stack(&stack_b);
	argc -= 1;
	while (argc >= i)
	{
		j = 1;
		if (argv[argc][0] == '-')
			while (argv[argc][j])
			{
				if (ft_isdigit(argv[argc][j]) == 0)
					return (parse_error(2));
				j++;
			}
		else if (ft_isdigit(*argv[argc]) == 0)
			return (parse_error(2));
		add_elem(&stack_a, ft_atoi(argv[argc]));
		argc--;
	}
	print_stack(&stack_a);
	return (0);
}
