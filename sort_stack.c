/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:10:21 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/24 19:28:26 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_elem	*find_min(t_stack *a)
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

int				rotate_to_min(t_stack *a)
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

int				push_min_b(t_stack *a, t_stack *b)
{
	rotate_to_min(a);
	push(a, b);
	return (0);
}

int				sort_stack(t_stack *a, t_stack *b)
{
	while (a->nbr > 1)
		push_min_b(a, b);
	while (b->nbr != 0)
		push(b, a);
	print_stack(a);
	ft_printf("\n---%d\n\n", g_op_count);
	print_stack(b);
	return (0);
}
