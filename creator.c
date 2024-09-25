/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:24:59 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 10:01:32 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_rescreator(int argc, char **argv)
{
	int		j;
	char	**res;

	if (argc == 2)
		res = ft_split(argv[1], ' ');
	else
	{
		res = malloc(argc * sizeof(char *));
		if (!res)
			return (NULL);
		j = 1;
		while (j < argc)
		{
			res[j - 1] = argv[j];
			j++;
		}
		res[j - 1] = NULL;
	}
	return (res);
}

t_list	*new_num(int val, int index, int pos, char box)
{
	t_list	*num;

	num = (t_list *)malloc(sizeof(t_list));
	if (num != NULL)
	{
		num->val = val;
		num->index = index;
		num->pos = pos;
		num->box = box;
		num->cos = 0;
		num->prev = 0;
		num->next = NULL;
	}
	return (num);
}

int	ft_not_alpha(char **res)
{
	int	j;
	int	i;

	j = 0;
	while (res[j] != NULL)
	{
		i = 0;
		while (i < ft_strlen(res[j]))
		{
			if (ft_isalpha(res[j][i]) == 1)
			{
				ft_printf("Error\n");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_number(char **res)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	while (res[i] != NULL)
	{
		if (ft_atoi(res[i]) > 2147483647 || ft_atoi(res[i]) < -2147483648)
			k = 0;
		j = i + 1;
		while (res[j] != NULL)
		{
			if (ft_atoi(res[i]) == ft_atoi(res[j]))
				k = 0;
			j++;
		}
		i++;
	}
	if (k == 0)
		ft_printf("Error\n");
	return (k);
}

void	fill_sort_index_a(t_list **a, char **res, int argc, char **argv)
{
	int		i;
	t_list	*c_a;

	c_a = *a;
	i = 1;
	while (res[i] != NULL)
	{
		(*a)->next = new_num(ft_atoi(res[i]), i + 1, i + 1, 'a');
		*a = (*a)->next;
		i++;
	}
	*a = c_a;
	sort_index(*a);
	ft_first_validation(a, res, argc, argv);
}
