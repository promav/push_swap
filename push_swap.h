/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:40:32 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 10:16:21 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct list
{
	int			val;
	int			index;
	int			pos;
	char		box;
	int			cos;
	int			prev;
	struct list	*next;
}	t_list;

int				ft_isalpha(int c);
void			*ft_memcpy(void *dest, const void *src, size_t n);
long			ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
int				ft_strlen( char const *s);
int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_putnbr(int n);
int				ft_putunbr(unsigned int n);
int				ft_putvoid(uintptr_t n);
int				ft_putstr(char *s);
int				ft_puthexa(unsigned long long n, char c);
t_list			*new_num(int val, int index, int pos, char box);
int				max_index(t_list *list);
int				min_index(t_list *list);
int				ft_size(t_list *list);
t_list			*sort_pos(t_list *list, t_list *list2, t_list *temp);
t_list			*sort_neg(t_list *list, t_list *list2, t_list *temp);
void			sort_index(t_list *list);
void			position(t_list **list, t_list **c);
int				ft_swap(t_list **list, t_list **c, int a);
int				ft_swap_swap(t_list **x, t_list **y, \
t_list **c_x, t_list **c_y);
int				ft_rotate(t_list **list, t_list **c, int a);
int				ft_rot_rot(t_list **x, t_list **y, t_list **c_x, t_list **c_y);
int				ft_rrotate(t_list **list, t_list **c, int a);
int				ft_rrot_rrot(t_list **x, t_list **y, \
t_list **c_x, t_list **c_y);
int				ft_push(t_list **x, t_list **y, t_list **c_x, t_list **c_y);
int				first_step(t_list **x, t_list **y, t_list **c_x, t_list **c_y);
void			sort_3elements(t_list **x, t_list **c_x);
void			ft_prep_cost_no_max(t_list *x, t_list *y);
void			ft_prep_cost(t_list *x, t_list *y);
void			ft_cost(t_list *x, t_list *y);
int				ft_mov(t_list **x, t_list **y, t_list **c_x, t_list **c_y);
int				ft_last_rotation(t_list **x, t_list **c_x);
void			ft_free(t_list **x);
void			*freessplit(char **str, int k);
unsigned int	mallocsize(char const *str, char c);
int				min_cost(t_list *x);
int				ft_prep_mov_2(t_list **x, t_list **y);
int				ft_mov(t_list **x, t_list **y, t_list **c_x, t_list **c_y);
char			**ft_rescreator(int argc, char **argv);
int				ft_not_alpha(char **res);
int				ft_number(char **res);
int				ft_valid_arg(int argc, char **argv);
void			fill_sort_index_a(t_list **x, char **res, \
int argc, char **argv);
void			ft_first_validation(t_list **x, char **res, \
int argc, char **argv);
int				ft_push_swap(t_list **x, t_list **y);
int				min(int a, int b);
int				max(int a, int b);
int				min_cost_min_indx(t_list *x, int a);
int				ft_mov1(t_list **x, t_list **y, int *p, int *s);
void			ft_pos_prev(t_list **x, int *p);

#endif
