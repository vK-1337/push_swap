/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:32 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/17 23:44:06 by vk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

int		ft_is_same(int ac, char **av);
int		ft_parse(int ac, char **av);
int		ft_check_validity(char *str);
int		ft_check_single_arg(char *str);
int		ft_already_sorted(t_list **list);
int		ft_find_lst_max(t_list **list);
int		ft_find_lst_min(t_list **list);
int		ft_check_multiple_args(int ac, char **av);
int		ft_content_diff(t_list *a_list_node, t_list *b_list_node);

//  COST.C
int		ft_cost(int a_node_pos, int b_node_pos, t_list **list_a,
			t_list **list_b);
void	ft_single_cost_a(int *cost, int *a_node_pos, int a_size);
void	ft_single_cost_b(int *cost, int *b_node_pos, int b_size);
void	ft_multiple_costs(int *cost, int *a_node_pos, int *b_node_pos,
			int a_size, int b_size);

typedef struct s_target_info
{
	int	target_pos;
	int	pos_to_insert;
}		t_target_info;

void ft_execute_moves(t_list **list_a, t_list **list_b, t_target_info positions);
void ft_move_a(int *a_node_pos, t_list **list_a);
void ft_move_b(int *b_node_pos, t_list **list_b);
void	ft_sort(t_list **list_a);
void ft_multiple_moves(int *a_node_pos, int *b_node_pos, t_list **list_a, t_list **list_b);

t_target_info	ft_cheapest_moves(t_list **list_a, t_list **list_b);
t_list	*ft_make_list(char **str_tab, int ac);
void	ft_three_sort_a(t_list **list);
void	ft_free_list(t_list **list);

void	ft_swap_node(t_list *a, t_list *b);
void	ft_swap_rr(t_list **list_a, t_list **list_b);
void	ft_swap_pa(t_list **list_a, t_list **list_b);
void	ft_swap_ra(t_list **list_a);
void	ft_swap_rb(t_list **list_b);
void	ft_swap_a(t_list **list);
void	ft_swap_b(t_list **list);
void	ft_swap_ss(t_list **list_a, t_list **list_b);
void	ft_swap_pb(t_list **list_a, t_list **list_b);
void	ft_swap_rra(t_list **list_a);
void	ft_swap_rrb(t_list **list_b);
void	ft_swap_rrr(t_list **list_a, t_list **list_b);

#endif
