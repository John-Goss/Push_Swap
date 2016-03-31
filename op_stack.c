/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:38:45 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/31 15:26:48 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			push(t_stack *a, t_stack *b)
{
	t_elem	*tmp;

	if (!a || !a->first)
		return (-1);
	add_elem(b, a->first->nbr);
	if (a->nbr < 2)
		tmp = a->first;
	else
		tmp = a->first->next;
	tmp->prev = NULL;
	free(a->first);
	a->first = tmp;
	a->nbr--;
	g_op_count += 1;
	return (0);
}

int			swap(t_stack *stack)
{
	int	tmp;

	if (!stack || stack->nbr < 2)
		return (-1);
	tmp = stack->first->nbr;
	stack->first->nbr = stack->first->next->nbr;
	stack->first->next->nbr = tmp;
	g_op_count += 1;
	ft_printf("sa ");
	return (0);
}

static int	ft_ret(int reverse)
{
	g_op_count += 1;
	reverse == 0 ? ft_printf("ra ") : ft_printf("rra ");
	return (0);
}

int			rotate(t_stack *stack, int reverse)
{
	t_elem	*tmp;

	if (!stack || stack->nbr < 2)
		return (-1);
	if (reverse == 0)
	{
		tmp = stack->first->next;
		stack->last->next = stack->first;
		stack->first->next = NULL;
		stack->first->prev = stack->last;
		stack->last = stack->first;
		stack->first = tmp;
	}
	else if (reverse == 1)
	{
		tmp = stack->last->prev;
		tmp->next = NULL;
		stack->last->next = stack->first;
		stack->last->prev = NULL;
		stack->first->prev = stack->last;
		stack->last = tmp;
		stack->first = stack->first->prev;
	}
	return (ft_ret(reverse));
}
