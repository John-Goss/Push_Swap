/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:54:07 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/25 16:30:02 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *a)
{
	t_elem	*next;
	t_elem	*min;

	min = a->first;
	next = min->next;
	if (min->nbr < next->nbr)
	{
		next = next->next;
		if (min->nbr < next->nbr)
			if (next->prev->nbr > next->nbr)
			{
				rotate(a, 1);
				swap(a);
			}
	}
}
