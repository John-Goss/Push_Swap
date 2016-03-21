/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:38:45 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/21 18:05:51 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || stack->nbr < 2)
		return (0);
	tmp = stack->first->nbr;
	stack->first->nbr = stack->first->next->nbr;
	stack->first->next->nbr = tmp;
	return (1);
}

int	rotate(t_stack *stack)
{
	t_elem	*tmp;

	if (!stack || stack->nbr < 2)
		return (0);
	tmp = stack->first->next;
	stack->last->next = stack->first;
	stack->first->next = NULL;
	stack->first->prev = stack->last;
	stack->last = stack->first;
	stack->first = tmp;
	return (1);
}
