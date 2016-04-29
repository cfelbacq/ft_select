/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:45:58 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/05 13:47:59 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strln(int n)
{
	int i;
	int size;

	i = 1;
	size = 0;
	if (n == -2147483648)
	{
		size = 11;
		return (size);
	}
	if (n < 0)
	{
		size = 1;
		n = n * -1;
	}
	while (n >= i)
	{
		size++;
		i = i * 10;
	}
	return (size);
}

static char	*itoa_2pt(char *s, int i, int j, int n)
{
	if (n == -2147483648)
	{
		s = ft_strdup("-2147483648");
		return (s);
	}
	if (n < 0)
	{
		s[j] = '-';
		n = n * -1;
		j++;
	}
	while ((n / i) >= 10)
		i = i * 10;
	while (i > 0)
	{
		s[j] = (n / i) % 10 + '0';
		j++;
		i = i / 10;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		j;

	s = NULL;
	i = 1;
	j = 0;
	s = (char *)malloc(sizeof(char) * ft_strln(n) + 1);
	if (s == NULL)
		return (NULL);
	s = itoa_2pt(s, i, j, n);
	s[ft_strln(n) + 1] = '\0';
	return (s);
}
