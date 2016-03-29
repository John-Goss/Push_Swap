/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:24:32 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/29 13:15:43 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_stacks(t_stack *a, t_stack *b)
{
	a->nbr = 0;
	a->first = NULL;
	a->last = NULL;
	b->nbr = 0;
	b->first = NULL;
	b->last = NULL;
}

static	int		check_dbl(t_stack *stack)
{
	t_elem	*ptr;
	t_elem	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		ptr = tmp->next;
		while (ptr)
		{
			if (ptr->nbr == tmp->nbr)
				return (parse_error(3));
			ptr = ptr->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int				add_elem(t_stack *stack, long nbr)
{
	t_elem	*elem;

	if (!(elem = (t_elem *)malloc(sizeof(*elem))))
		return (-1);
	if (nbr != (int)nbr)
		return (parse_error(4));
	elem->nbr = (int)nbr;
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
	check_dbl(stack);
	return (0);
}

void			free_list(t_stack *stack)
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

int				parse_stack(int argc, char **argv, int i)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		j;

	init_stacks(&stack_a, &stack_b);
	while (--argc >= i)
	{
		j = 0;
		if (argv[argc][j] == '-' && argv[argc][j + 1])
			while (argv[argc][++j])
			{
				if (ft_isdigit(argv[argc][j]) == 0)
					return (parse_error(2));
			}
		else if (ft_isdigit(*argv[argc]) == 0)
			return (parse_error(2));
		add_elem(&stack_a, ft_atoi_long(argv[argc]));
	}
	sort_stack(&stack_a, &stack_b);
	return (0);
}
