/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:57:03 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/03 13:46:49 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		new = (char *)malloc(sizeof(char) * len + 1);
		if (new == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			new[i] = (*f)(s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
