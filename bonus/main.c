/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:01:13 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 11:08:51 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker_free_a_b(t_list **a, t_list **b)
{
	ft_checker(a, b);
	ft_free(a);
	ft_free(b);
}

int	main(int argc, char **argv)
{
	char	**res;
	t_list	*a;
	t_list	*b;

	if (argc <= 1)
		return (0);
	res = ft_rescreator(argc, argv);
	if (ft_not_alpha(res) == 0 || ft_number(res) == 0
		|| ft_valid_arg(argc, argv) == 0)
	{
		if (argc == 2)
			freessplit(res, mallocsize(argv[1], ' '));
		else
			free(res);
		return (0);
	}
	b = NULL;
	a = new_num(ft_atoi(res[0]), 1, 1, 'a');
	fill_sort_index_a(&a, res);
	ft_checker_free_a_b(&a, &b);
	if (argc == 2)
		freessplit(res, mallocsize(argv[1], ' '));
	else
		free(res);
	return (0);
}
