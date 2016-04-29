/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:18:48 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/04 11:05:29 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		sizeofstr;
	char	*s2;
	int		i;

	if (s1 == NULL)
		return (NULL);
	sizeofstr = ft_strlen(s1);
	s2 = NULL;
	i = 0;
	s2 = (char *)malloc((sizeofstr * sizeof(char)) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
