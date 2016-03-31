/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:29:37 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/31 13:39:04 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;

	g_opt_r = 0;
	g_opt_c = 0;
	g_opt_v = 0;
	i = 0;
	if (ac < 3)
	{
		if (ac == 1 || ac < 1)
			return (0);
		else
		{
			if (av[1][i] == '-')
				i++;
			while (av[1][i])
			{
				if (ft_isdigit(av[1][i++]) == 0)
					return (0);
			}
		}
	}
	parse_opt(ac, av);
	return (0);
}
