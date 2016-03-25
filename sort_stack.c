/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:10:21 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/25 16:30:06 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*find_min(t_stack *a)
{
	t_elem	*min;
	t_elem	*ptr;

	if (!a)
		return (NULL);
	if (a->nbr < 2)
		return (a->first);
	min = a->first;
	ptr = min->next;
	while (ptr)
	{
		if (ptr->nbr < min->nbr)
			min = ptr;
		ptr = ptr->next;
	}
	return (min);
}

int		rotate_to_min(t_stack *a)
{
	int		i;
	t_elem	*min;
	t_elem	*ptr;

	i = 0;
	min = find_min(a);
	ptr = a->first;
	while (ptr && ptr->nbr != min->nbr)
	{
		i++;
		ptr = ptr->next;
	}
	if (i > (a->nbr / 2))
		while (i++ < a->nbr)
			rotate(a, 1);
	else
		while (i-- > 0)
			rotate(a, 0);
	return (0);
}

int		push_min_b(t_stack *a, t_stack *b)
{
	rotate_to_min(a);
	push(a, b);
	return (0);
}

int		is_sort(t_stack *a)
{
	t_elem	*ptr;

	ptr = a->first;
	while (ptr->next)
	{
		if (ptr->nbr > ptr->next->nbr)
			return (-1);
		ptr = ptr->next;
	}
	return (0);
}

int		sort_stack(t_stack *a, t_stack *b)
{
	if (is_sort(a) == 0)
		return (print_stack(a));
	else if (a->nbr == 3)
	{
		swap_stack(a);
		return (print_stack(a));
	}
	else
	{
		while (a->nbr > 1)
			push_min_b(a, b);
		while (b->nbr != 0)
			push(b, a);
		return (print_stack(a));
	}
	return (0);
}
