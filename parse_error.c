/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:05:25 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/21 13:10:44 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_error(int error_code)
{
	if (error_code == 1)
		ft_putendl_fd("ERROR : Multi Same Flag or Wrong Flag.", 2);
	else if (error_code == 2)
		ft_putendl_fd("ERROR : Not Valid Argument.", 2);
	else
		ft_putendl_fd("UNKNOWN ERROR.", 2);
	exit(-1);
}
