/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:24:34 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 15:27:59 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_pos(t_list *list, t_list *list2, t_list *temp)
{
	int	swap;

	if (list->index < list2->index)
	{
		swap = list2->index;
		list2->index = list->index;
		list->index = swap;
		list2 = temp;
	}
	else
		list2 = list2->next;
	return (list2);
}

t_list	*sort_neg(t_list *list, t_list *list2, t_list *temp)
{
	int	swap;

	if (list->index > list2->index)
	{
		swap = list2->index;
		list2->index = list->index;
		list->index = swap;
		list2 = temp;
	}
	else
		list2 = list2->next;
	return (list2);
}

void	sort_index(t_list *list)
{
	t_list	*temp;
	t_list	*list2;

	temp = list;
	while (list != NULL)
	{
		list2 = temp;
		while (list2 != NULL)
		{
			if (list->val > list2->val)
				list2 = sort_pos(list, list2, temp);
			else if (list->val < list2->val)
				list2 = sort_neg(list, list2, temp);
			else
				list2 = list2->next;
		}
		list = list->next;
	}
	list = temp;
}

int	ft_swap(t_list **list, t_list **c, int a)
{
	t_list	*first;
	t_list	*second;

	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	*list = second;
	position(list, c);
	if (a == 0)
		ft_printf("s%c\n", (*list)->box);
	return (1);
}

int	ft_swap_swap(t_list **x, t_list **y, t_list **c_x, t_list **c_y)
{
	int	a;

	a = 0;
	a = ft_swap(x, c_x, 1);
	a = ft_swap(y, c_y, 1);
	ft_printf("ss\n");
	return (a);
}
