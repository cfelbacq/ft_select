/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:57:07 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/02 18:06:38 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int ret;
	int j;

	j = 0;
	ret = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r' \
		|| str[i] == '\f' || str[i] == '\v')
	{
		i++;
		j++;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	if (str[j] == '-')
		ret = ret * -1;
	if (str[j] == '+')
		ret = ret * 1;
	return (ret);
}
