/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:48:28 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/01 17:49:47 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return ((char *)s1 + i);
	while (s1[i] != '\0')
	{
		while (s1[i + j] == s2[j] && s2[j] != '\0')
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
