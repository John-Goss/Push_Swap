/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:39:23 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/25 13:46:27 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print(t_stack *stack)
{
	t_elem *elem;

	elem = stack->first;
	while (elem && stack->nbr > 0)
	{
		if (g_opt_c == 1)
			ft_printf("------\n%s%d%s\n------\n", RED, elem->nbr, RST);
		else
			ft_printf("------\n%d\n------\n", elem->nbr);
		elem = elem->next;
	}
}

int			print_stack(t_stack	*a)
{
	if (g_opt_v == 1)
		print(a);
	if (g_opt_r == 1)
		ft_printf("Nombre d'operations : %d\n", g_op_count);
	return (0);
}
