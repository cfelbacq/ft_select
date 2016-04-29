/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:54:07 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/03 13:04:18 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		new = NULL;
		new = (char *)malloc(sizeof(char) * len + 1);
		if (new == NULL)
			return (NULL);
		while (i < len)
		{
			new[i] = s[i + start];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
