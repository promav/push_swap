/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders2ch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:02:46 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 11:09:25 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_ch(t_list **list, t_list **c)
{
	t_list	*first;
	t_list	*second;

	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	*list = second;
	position(list, c);
}

void	ft_swap_swap_ch(t_list **x, t_list **y, t_list **c_x, t_list **c_y)
{
	ft_swap_ch(x, c_x);
	ft_swap_ch(y, c_y);
}

void	ft_checker(t_list **a, t_list **b)
{
	char	buffer[100];
	ssize_t	r;
	int		size;

	size = ft_size(*a);
	r = read(0, buffer, sizeof(buffer));
	buffer[r] = '\0';
	while (buffer[0] != '\0')
	{
		if (ft_instruction_1(a, b, buffer) == 1
			|| ft_instruction_2(a, b, buffer) == 1)
		{
			r = read(0, buffer, sizeof(buffer));
			buffer[r] = '\0';
		}
		else
		{
			ft_printf("Error\n");
			return ;
		}
	}
	ft_validator(a, size);
}

int	ft_instruction_1(t_list **a, t_list **b, char *r)
{
	t_list	*c_a;
	t_list	*c_b;

	c_a = *a;
	c_b = *b;
	if (r[0] == 's' && r[1] == 'a' && r[2] == '\n' && ft_size(*a) > 1)
		ft_swap_ch(a, &c_a);
	else if (r[0] == 's' && r[1] == 'b' && r[2] == '\n' && ft_size(*b) > 1)
		ft_swap_ch(b, &c_b);
	else if (r[0] == 's' && r[1] == 's' && r[2] == '\n'
		&& ft_size(*a) > 1 && ft_size(*b) > 1)
		ft_swap_swap_ch(a, b, &c_a, &c_b);
	else if (r[0] == 'r' && r[1] == 'a' && r[2] == '\n' && ft_size(*a) > 1)
		ft_rotate_ch(a, &c_a);
	else if (r[0] == 'r' && r[1] == 'b' && r[2] == '\n' && ft_size(*b) > 1)
		ft_rotate_ch(b, &c_b);
	else if (r[0] == 'r' && r[1] == 'r' && r[2] == '\n'
		&& ft_size(*a) > 1 && ft_size(*b) > 1)
		ft_rot_rot_ch(a, b, &c_a, &c_b);
	else
		return (0);
	return (1);
}

int	ft_instruction_2(t_list **a, t_list **b, char *r)
{
	t_list	*c_a;
	t_list	*c_b;

	c_a = *a;
	c_b = *b;
	if (r[0] == 'r' && r[1] == 'r' && r[2] == 'a' && r[3] == '\n'
		&& ft_size(*a) > 1)
		ft_rrotate_ch(a, &c_a);
	else if (r[0] == 'r' && r[1] == 'r' && r[2] == 'b' && r[3] == '\n'
		&& ft_size(*b) > 1)
		ft_rrotate_ch(b, &c_b);
	else if (r[0] == 'r' && r[1] == 'r' && r[2] == 'r' && r[3] == '\n'
		&& ft_size(*a) > 1 && ft_size(*b))
		ft_rrot_rrot_ch(a, b, &c_a, &c_b);
	else if (r[0] == 'p' && r[1] == 'a' && r[2] == '\n' && ft_size(*b) >= 1)
		ft_push_ch(a, b, &c_a, &c_b);
	else if (r[0] == 'p' && r[1] == 'b' && r[2] == '\n' && ft_size(*a) >= 1)
		ft_push_ch(b, a, &c_b, &c_a);
	else
		return (0);
	return (1);
}
