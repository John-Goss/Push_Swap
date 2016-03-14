/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:24:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/14 15:49:21 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct		s_parse
{
	int				v;
	int				c;
	struct s_parse	*next;
	struct s_parse	*prev;
}					t_parse;

void	parse_fct(char *argv);

#endif
