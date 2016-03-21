/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:23:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/21 13:22:39 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_opt(t_opt *opt)
{
	opt->v = 0;
	opt->c = 0;
	opt->r = 0;
}

static int	set_opt(t_opt *opt, char *av)
{
	int	i;

	i = 0;
	if (!av[i])
		return (-1);
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 1)
			return (0);
		else if (av[i] == 'v' && opt->v == 0)
			opt->v += 1;
		else if (av[i] == 'c' && opt->c == 0)
			opt->c += 1;
		else if (av[i] == 'r' && opt->r == 0)
			opt->r += 1;
		else
			return (-1);
		i++;
	}
	if (opt->v > 1 || opt->c > 1 || opt->r > 1)
		return (parse_error(1));
	return (1);
}

int			parse_opt(int ac, char **argv)
{
	t_opt	opt;
	int		i;

	i = 1;
	g_op_count = 0;
	init_opt(&opt);
	while (i < ac)
	{
		if (argv[i][0] == '-')
		{
			if (set_opt(&opt, argv[i] + 1) == -1)
				return (parse_error(1));
			else if (set_opt(&opt, argv[i] + 1) == 0)
				break ;
		}
		i++;
	}
	parse_stack(ac, argv, i);
	return (1);
}
