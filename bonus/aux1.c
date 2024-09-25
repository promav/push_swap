/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:55:13 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 11:04:57 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_size(t_list *list)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = list;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	list = temp;
	return (i);
}
