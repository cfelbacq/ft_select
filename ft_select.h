/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 12:16:48 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/04/30 14:33:32 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <unistd.h>
#include <termios.h>
#include <termcap.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef	struct	s_node
{
	char *data;
	struct s_node *next;
	struct s_node *prev;
}				t_node;

typedef	struct	s_dlist
{
	size_t length;
	struct s_node *tail;
	struct s_node *head;
}				t_dlist;

#endif
