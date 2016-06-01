/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:47:43 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/06/01 15:30:54 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"

int	my_outc(int c);

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

void	print_underline(char *str, int highlight)
{
	char *res;
	char *res1;
	char *res2;
	char *res3;

	res2 = tgetstr("mr", NULL);
	res3 = tgetstr("me", NULL);
	res = tgetstr("us", NULL);
	res1 = tgetstr("ue", NULL);
	tputs(res, 0, my_outc);
	if (highlight == 1)
		tputs(res2, 0, my_outc);
	ft_putstr(str);
	if (highlight == 1)
		tputs(res3, 0, my_outc);
	tputs(res1, 0, my_outc);
}

void	print_highlight(char *str)
{
	char *res;
	char *res1;
	char *res2;
	char *res3;

	res = tgetstr("mr", NULL);
	res1 = tgetstr("me", NULL);
	tputs(res, 0, my_outc);
	ft_putstr(str);
	tputs(res1, 0, my_outc);
}

void	cursor_motion(int nb_li)
{
	char *res;
	char *res1;
	char *res2;
	int i;

	i = 0;
	res = tgetstr("cm", NULL);
	res1 = tgetstr("cr", NULL);
	res2 = tgetstr("up", NULL);
	tputs(tgoto(res, 0, 0), 0, my_outc);
	tputs(res1, 0, my_outc);
	while (i < nb_li)
	{
		tputs(res2, 0, my_outc);
		i++;
	}
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
		if (list->cursor_on == 1)
			print_underline(list->data, list->highlight);
		else
		{
			if (list->highlight == 1)
				print_highlight(list->data);
			else
				ft_putstr(list->data);
		}
		while (ft_strlen(list->data) + j <= len_max_word)
		{
			ft_putchar(' ');
			j++;
		}
		list = list->next;
		j = 0;
		i++;
	}
	cursor_motion(n_li);
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
	new->cursor_on = 0;
	new->highlight = 0;
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
	list->cursor_on = 1;
	list->highlight = 0;
	list->next = NULL;
	tmp = list;
	while (++i < argc)
	{
		tmp->next = get_list(tmp, argv[i]);
		tmp = tmp->next;
	}
	return (list);
}

int	my_outc(int c)
{
	ft_putchar(c);
	return (0);
}

t_node	*search_cursor(t_node *list)
{
	t_node *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->cursor_on == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (list);
}

void	del_node(t_node **list, t_dlist ***feature_list)
{
	t_node *tmp;
	t_node *tmp1;
	t_dlist *tmp_d;

	tmp_d = **feature_list;
	tmp = *list;
	tmp1 = NULL;
	if (tmp->prev == NULL)
	{
		tmp->next->prev = NULL;
		tmp_d->head = tmp->next;
		tmp_d->length--;
	}
}

int		get_key(t_node **list, t_dlist **feature_list)
{
	char buff[3];
	char *res;
	int pos_x;
	int pos_y;
	t_node *tmp;

	tmp = search_cursor(*list);
	pos_x = 0;
	pos_y = 0;
	res = NULL;
		read(0, buff, 3);
		if (buff[0] == 27)
		{
			if (buff[2] == 'C')
			{
				tmp->cursor_on = 0;
				if (tmp->next != NULL)
					tmp = tmp->next;
				tmp->cursor_on = 1;
			}
			else if (buff[2] == 'D')
			{
				tmp->cursor_on = 0; // gauche
				if (tmp->prev != NULL)
					tmp = tmp->prev;
				tmp->cursor_on = 1;
			}
		/*	else if (buff[2] == 'B')
				; // bas
			else if (buff[2] == 'A')
				; // haut*/
		}
		if (buff[0] == ' ' && tmp->cursor_on == 1)
		{
			if (tmp->highlight == 1)
				tmp->highlight = 0;
			else if (tmp->highlight == 0)
				tmp->highlight = 1;
			tmp->cursor_on = 0;
			if (tmp->next != NULL)
			tmp = tmp->next;
			tmp->cursor_on = 1;
		}
		if (buff[0] == 127)
		{
			del_node(&tmp, &feature_list);
		}
	return (0);
}

int	main(int argc, char **argv, char **env)
{

	char	*name_term;
	int 	len_max_word;
	t_node	*list;
	t_dlist *feature_list;
	struct	termios term;
	char *res;

	list = NULL;
	list = init_list(argc, argv);
	feature_list = init_feature_list(argc, list);
	len_max_word = get_len_max(argv, argc);
	name_term = getenv("TERM");
	tgetent(NULL, name_term);
	tcgetattr(0, &term);

	term.c_lflag &= ~(ICANON); // MET LE TERMINAL EN MODE CANONIQUE
	term.c_lflag &= ~(ECHO); // Les touches tapees ne s'inscriront plu dans le TERMINAL
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	res = tgetstr("cl", NULL);
	tputs(res, 0, my_outc);
	while (1)
	{
		show_list(list, feature_list, name_term, len_max_word);
		get_key(&list, &feature_list);
	}
	return (0);
}
