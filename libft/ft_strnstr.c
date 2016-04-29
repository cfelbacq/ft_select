/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:02:54 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/02 17:55:57 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < n && s1[i] != '\0')
	{
		while (s1[i + j] == s2[j] && s2[j] != '\0' && (i + j < n))
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		j = 0;
		i++;
	}
	return (NULL);
}
