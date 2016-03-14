/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:21:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/14 17:24:00 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_opt(t_opt *opt)
{
	opt->v = 0;
	opt->c = 0;
}

static void	set_opt(t_opt *opt, char *argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		while (ft_isdigit(argv[i]) == 1)
			i++;
		if (argv[i] != 'v' && argv[i] != 'c')
			return (0);
		else if (argv[i] == 'v')
			opt->v = 1;
		else if (argv[i] == 'c')
			opt->c = 1;
		i++;
	}
	return (1);
}

void		parse_opt(char **argv)
{
	t_opt	opt;
	int		i;

	i = 1;
	init_opt(&opt);
	while (argv[i])
	{
		if (argv[i][0] == '-')
			set_opt(&opt, argv[i]);
		i++;
	}
}
