/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:47:43 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/04/25 13:47:45 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include "libft/libft.h"

int	get_len_max(char **argv, int argc)
{
	int i;
	int len;

	len = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > len)
			len = ft_strlen(argv[i]);
		i++;
	}
	return (len);
}

void	show_ar(char **ar, int ac, char *name_term, int len_max_word)
{
	int		n_co;
	int		n_li;
	int i;
	int j;
	int	nb_word_max_in_line;

	nb_word_max_in_line = 0;
	i = 1;
	j = 0;
	while (i < ac)
	{
		tgetent(NULL, name_term);
		n_li = tgetnum("li");
		n_co = tgetnum("co");
		nb_word_max_in_line = n_co / len_max_word;
		if (i % nb_word_max_in_line == 0)
			ft_putchar('\n');
		ft_putstr(ar[i]);
		while (ft_strlen(ar[i]) + j <= len_max_word)
		{
			ft_putchar(' ');
			j++;
		}
		j = 0;
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{

	char	*name_term;
	int len_max_word;

	len_max_word = get_len_max(argv, argc);
	name_term = getenv("TERM");
	show_ar(argv, argc, name_term, len_max_word);
	return (0);
}