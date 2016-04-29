/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:03:46 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/03 12:22:38 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	int		n;
	size_t	len_dst;
	size_t	len_src;
	int		i;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	n = size - len_dst - 1;
	i = 0;
	if (n < 0)
		return (size + len_src);
	else
		while (i < n && src[i] != '\0')
		{
			dest[len_dst + i] = src[i];
			i++;
		}
	dest[len_dst + i] = '\0';
	return (len_dst + len_src);
}
