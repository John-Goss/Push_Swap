/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:39:23 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/21 17:15:24 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_elem *elem;

	elem = stack->first;
	while (elem)
	{
	//	if (opt->c == 1)
	//		ft_printf("%s%d%s\n", RED, elem->nbr, RST);
	//	else
			ft_printf("%d\n", elem->nbr);
		elem = elem->next;
	}
}
