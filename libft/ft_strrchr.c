/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:29:41 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/11/27 18:02:25 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len_s;

	len_s = ft_strlen(s);
	if (s[len_s] == c)
		return ((char *)s + len_s);
	while (len_s > -1)
	{
		if (s[len_s] == c)
			return ((char *)s + len_s);
		len_s--;
	}
	return (NULL);
}
