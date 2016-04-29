/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:18:22 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/03 13:47:54 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1)
{
	char			*new;
	size_t			len;
	unsigned int	start;
	size_t			j;

	j = 1;
	new = NULL;
	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (s1[start] == ' ' || s1[start] == '\t' || s1[start] == '\n' \
		|| s1[start] == ',')
		start++;
	while (s1[len - j] == ' ' || s1[len - j] == '\t' || s1[len - j] == '\n' \
		|| s1[len - j] == ',')
		j++;
	if (s1[start] == '\0')
		j = 0;
	else
		j--;
	new = ft_strsub(s1, start, (len - start - j));
	if (new == NULL)
		return (NULL);
	return (new);
}
