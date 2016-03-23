/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:38:45 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/22 13:53:35 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	if (!a)
		return (-1);
	add_elem(b, a->first->nbr);
	tmp = a->first->next;
	tmp->prev = NULL;
	free(a->first);
	a->first = tmp;
	return (0);
}

int	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || stack->nbr < 2)
		return (-1);
	tmp = stack->first->nbr;
	stack->first->nbr = stack->first->next->nbr;
	stack->first->next->nbr = tmp;
	return (0);
}

int	rotate(t_stack *stack, int reverse)
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
	return (0);
}
