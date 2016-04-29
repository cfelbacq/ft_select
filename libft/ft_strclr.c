/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:37:00 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/03 13:28:35 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t i;
	size_t j;

	j = 0;
	if (s != NULL)
	{
		i = ft_strlen(s);
		while (j < i)
		{
			s[j] = '\0';
			j++;
		}
	}
	return ;
}
