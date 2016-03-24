/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:23:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/24 17:54:43 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_opt(char *av)
{
	int	i;

	i = 0;
	if (!av[i])
		return (-1);
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 1 && (av[i - 1] != '-' || av[i + 1]))
			return (-1);
		else if (ft_isdigit(av[i]) == 1)
			return (0);
		else if (av[i] == 'v' && g_opt_v == 0)
			g_opt_v += 1;
		else if (av[i] == 'c' && g_opt_c == 0)
			g_opt_c += 1;
		else if (av[i] == 'r' && g_opt_r == 0)
			g_opt_r += 1;
		else
			return (-1);
		i++;
	}
	if (g_opt_v > 1 || g_opt_c > 1 || g_opt_r > 1)
		return (parse_error(1));
	return (1);
}

int			parse_opt(int ac, char **argv)
{
	int		i;

	i = 1;
	g_op_count = 0;
	while (i < ac)
	{
		if (argv[i][0] == '-')
		{
			if (set_opt(argv[i] + 1) == -1)
				return (parse_error(1));
			else if (set_opt(argv[i] + 1) == 0)
				break ;
		}
		else
			break ;
		i++;
	}
	parse_stack(ac, argv, i);
	return (1);
}
