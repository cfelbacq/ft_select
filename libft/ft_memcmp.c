/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:24:28 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/05 13:40:46 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t j;

	j = 0;
	while (j < n)
	{
		if (((unsigned char *)s1)[j] != ((unsigned char *)s2)[j])
			return (((unsigned char *)s1)[j] - ((unsigned char *)s2)[j]);
		j++;
	}
	return (0);
}
