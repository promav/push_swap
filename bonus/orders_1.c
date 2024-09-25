/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:01:23 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 15:24:55 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_valid_arg(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	i = 0;
	if (argc == 2)
		return (k);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			k = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				k = 0;
			j++;
		}
		i++;
	}
	if (k == 0)
		ft_printf("Error\n");
	return (k);
}

void	ft_validator(t_list **a, int s)
{
	t_list	*c;
	int		i;

	c = *a;
	i = 0;
	while (*a != NULL)
	{
		if ((*a)->index == (*a)->pos)
			i++;
		*a = (*a)->next;
	}
	*a = c;
	if (i == s)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
