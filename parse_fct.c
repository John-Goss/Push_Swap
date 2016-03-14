/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:21:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/14 15:49:23 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	init_parse(t_parse *parse, char *argv)
{
	parse->v = 0;
	parse->c = 0;
}

void	parse_fct(char *argv)
{
	t_parse	*parse;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-')
			init_parse(&parse, argv[i]);
		i++;
	}
}
