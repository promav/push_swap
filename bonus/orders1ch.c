/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders1ch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:01:30 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 11:09:15 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_ch(t_list **list, t_list **c)
{
	t_list	*first;
	t_list	*temp;

	first = *list;
	temp = (*list)->next;
	while ((*list)->next != NULL)
		*list = (*list)->next;
	(*list)->next = first;
	first->next = NULL;
	*list = temp;
	temp = *list;
	position(list, c);
}

void	ft_rot_rot_ch(t_list **x, t_list **y, t_list **c_x, t_list **c_y)
{
	ft_rotate_ch(x, c_x);
	ft_rotate_ch(y, c_y);
}

void	ft_rrotate_ch(t_list **list, t_list **c)
{
	t_list	*second_last;
	t_list	*last;

	second_last = NULL;
	last = *list;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *list;
	*list = last;
	last = *list;
	position(list, c);
}

void	ft_rrot_rrot_ch(t_list **x, t_list **y, t_list **c_x, t_list **c_y)
{
	if (ft_size(*x) > 1)
		ft_rrotate_ch(x, c_x);
	if (ft_size(*y) > 1)
		ft_rrotate_ch(y, c_y);
}

void	ft_push_ch(t_list **x, t_list **y, t_list **c_x, t_list **c_y)
{
	t_list	*first_y;
	t_list	*temp;

	temp = (*y)->next;
	first_y = *y;
	first_y->next = *x;
	if (first_y->box == 'a')
		first_y->box = 'b';
	else
		first_y->box = 'a';
	(*x) = first_y;
	*y = (*y)->next;
	*y = temp;
	position(x, c_x);
	position(y, c_y);
}
