/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:32 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/26 12:43:27 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_costs_info
{
	int	node_list_size;
	int	target_list_size;
}		t_costs_info;

// MAIN FUNCTION //
void	ft_push_swap(t_list **list_a);

// PARSING //
int		ft_is_same(int ac, char **av);
int		ft_parse(int ac, char **av);
int		ft_check_validity(char *str);
int		ft_check_single_arg(char *str);
int		ft_already_sorted(t_list **list);
int		ft_check_multiple_args(int ac, char **av);

// LST UTILS //
int		ft_find_lst_max_pos(t_list **list);
int		ft_find_lst_min_pos(t_list **list);
t_list	*ft_make_list(int ac, char **av);
t_list	*ft_get_node(t_list **list, int position);
void	ft_refresh_pos(t_list **list);
void	ft_print_list(t_list **list);
void	ft_print_node(t_list *node);
void	ft_free_list(t_list **list);

// INDEXS //
t_list	*ft_get_next_min(t_list **list, t_list *previous_min_node);
int		ft_get_first_min(t_list **list, t_list *previous_min_node);
void	ft_index_list(t_list **list);


// SORT //
void	ft_three_sort_a(t_list **list);
t_list *ft_best_push_pa(t_list **from_list, t_list **to_list);
void ft_final_sort(t_list **list_a);

// TARGETS //
int ft_define_target_pos(t_list *node, t_list **list);
int	ft_define_target_pos_pb(t_list *node, t_list **list);
int ft_get_closer_target(t_list *node_to_insert, t_list **list);
int	ft_define_target_pos_pa(t_list *node, t_list **list);
t_list *ft_best_push_pb(t_list **from_list, t_list **to_list);
t_list *ft_best_push_pa(t_list **from_list, t_list **to_list);

// COSTS //
int	ft_get_cost_greater_node(int *node_position, int *target_position,
		int *cost, t_costs_info infos);
    int	ft_get_cost_lower_node(int *node_position, int *target_position, int *cost,
		t_costs_info infos);
int	ft_get_cost_pa(t_list node, t_list target, t_list **node_list,
		t_list **target_list);
int	single_rotate_cost(int *position, int limit, int *cost);
int	multiple_rotates_down_lower(int *position1, int *position2, int *cost,
		t_costs_info infos);
int	multiple_rotates_down_greater(int *position1, int *position2, int *cost,
		t_costs_info infos);
int	multiple_rotates_up_lower(int *position1, int *position2, int *cost);
int	multiple_rotates_up_greater(int *position1, int *position2, int *cost);

// MOVES //
void	ft_multiple_moves_node_lesser(t_list **node, t_list **target_node,
		t_list **list_a, t_list **list_b);
void	ft_single_move_node_lesser(t_list **node, t_list **target_node,
t_list **list_a, t_list **list_b);
void	ft_push_to_b(t_list **list_a, t_list **list_b);

// INSTRUCTIONS //
void	ft_write_instruction(char *str);
void	ft_swap_node(t_list *a, t_list *b);
void	ft_swap_rr(t_list **list_a, t_list **list_b);
void	ft_swap_pa(t_list **list_a, t_list **list_b);
void	ft_swap_ra(t_list **list_a, int is_rr);
void	ft_swap_rb(t_list **list_b, int is_rr);
void	ft_swap_a(t_list **list);
void	ft_swap_b(t_list **list);
void	ft_swap_ss(t_list **list_a, t_list **list_b);
void	ft_swap_pb(t_list **list_a, t_list **list_b);
void	ft_swap_rra(t_list **list_a, int is_rrr);
void	ft_swap_rrb(t_list **list_b, int is_rrr);
void	ft_swap_rrr(t_list **list_a, t_list **list_b);

#endif
