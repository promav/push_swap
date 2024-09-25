/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:25:19 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 09:28:50 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position(t_list **list, t_list **c)
{
	int		i;
	t_list	*temp;

	temp = *list;
	i = 1;
	while (*list != NULL)
	{
		(*list)->pos = i;
		i++;
		*list = (*list)->next;
	}
	*list = temp;
	*c = *list;
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_pos_prev(t_list **x, int *p)
{
	t_list	*t;

	t = *x;
	while ((*x)->index != p[0])
		*x = (*x)->next;
	p[0] = (*x)->pos;
	p[1] = (*x)->prev;
	*x = t;
}

void	ft_free(t_list **x)
{
	t_list	*temp;

	while (*x != NULL)
	{
		temp = (*x)->next;
		free(*x);
		*x = temp;
	}
}
