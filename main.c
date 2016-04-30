/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:47:43 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/04/30 16:49:43 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"

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

void	show_list(t_node *list, t_dlist* feature, char *name_term, int len_max_word)
{
	int		n_co;
	int		n_li;
	int i;
	int j;
	int	nb_word_max_in_line;

	nb_word_max_in_line = 0;
	i = 0;
	j = 0;
	while (i < feature->length)
	{
		tgetent(NULL, name_term);
		n_li = tgetnum("li");
		n_co = tgetnum("co");
		nb_word_max_in_line = n_co / len_max_word;
		if (i % nb_word_max_in_line == 0 && i != 0)
			ft_putchar('\n');
		ft_putstr(list->data);
		while (ft_strlen(list->data) + j <= len_max_word)
		{
			ft_putchar(' ');
			j++;
		}
		list = list->next;
		j = 0;
		i++;
	}
}

void	print_list(t_node *list)
{
	while (list)
	{
		ft_putendl(list->data);
		list = list->next;
	}
}

t_node	*get_list(t_node *list, char *str)
{
	t_node *new;

	new = (t_node *)ft_memalloc(sizeof(t_node));
	new->prev = list;
	new->data = ft_strnew(ft_strlen(str) + 1);
	new->data = ft_strcpy(new->data, str);
	new->next = NULL;
	return (new);
}

t_dlist	*init_feature_list(int argc, t_node *list)
{
	t_node *tmp;
	t_dlist *new;
	
	new = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	new->length = argc - 1;
	new->head = list;
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->tail = tmp;
	return (new);
}

t_node	*init_list(int argc, char **argv)
{
	t_node	*list;
	int i;
	t_node *tmp;

	i = 1;
	list = (t_node *)ft_memalloc(sizeof(t_node));
	list->prev = NULL;
	list->data = ft_strnew(ft_strlen(argv[i]) + 1);
	list->data = ft_strcpy(list->data, argv[i]);
	list->next = NULL;
	tmp = list;
	while (++i < argc)
	{
		tmp->next = get_list(tmp, argv[i]);
		tmp = tmp->next;
	}
	return (list);
}

int	main(int argc, char **argv, char **env)
{

	char	*name_term;
	int 	len_max_word;
	t_node	*list;
	t_dlist *feature_list;

	list = NULL;
	list = init_list(argc, argv);
	feature_list = init_feature_list(argc, list);
	len_max_word = get_len_max(argv, argc);
	name_term = getenv("TERM");
	show_list(list, feature_list, name_term, len_max_word);
	return (0);
}
