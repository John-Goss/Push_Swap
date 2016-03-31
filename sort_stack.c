/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:10:21 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/31 15:31:55 by jle-quer         ###   ########.fr       */
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

int		last_sort(t_stack *a)
{
	t_elem	*ptr;

	ptr = a->first;
	while (ptr)
	{
		if (ptr->nbr < ptr->next->nbr)
			ptr = ptr->next;
		else if (ptr->next->next != NULL)
			return (1);
		else
			break ;
	}
	rotate(a, 1);
	rotate(a, 1);
	swap(a);
	rotate(a, 0);
	rotate(a, 0);
	return (0);
}

int		sort_stack(t_stack *a, t_stack *b)
{
	if (is_sort(a) == 0)
		return (print_stack(a));
	while (is_sort(a) != 0)
	{
		if (a->nbr > 3 && last_sort(a) == 0)
			break ;
		if (a->first->next && a->first->nbr > a->first->next->nbr)
			swap(a);
		rotate_to_min(a);
		if (is_sort(a) == 0)
			break ;
		push(a, b);
		ft_printf("pb ");
	}
	while (b->nbr != 0)
	{
		push(b, a);
		ft_printf("pa ");
	}
	ft_putchar('\n');
	return (print_stack(a));
}
