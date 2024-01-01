/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:04:45 by vda-conc          #+#    #+#             */
/*   Updated: 2024/01/01 21:51:22 by vk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_a(t_list *node, t_list *target_node, t_lists_container *lists, char **instructions)
{
    t_list	*list_min;
    t_list	*list_max;
    int		target_is_min;

    list_min = ft_get_node(&lists->list_a, ft_find_lst_min_pos(&lists->list_a));
    list_max = ft_get_node(&lists->list_a, ft_find_lst_max_pos(&lists->list_a));
    target_is_min = 0;
    if (node->content > list_max->content || node->content < list_min->content)
        target_is_min = 1;
    if (node->content < target_node->content || target_is_min == 1)
    {
        ft_multiple_moves_node_lesser(&node, &target_node, &lists->list_a, &lists->list_b,
            instructions);
        ft_single_move_node_lesser(&node, &target_node, &lists->list_a, &lists->list_b,
            instructions);
    }
    else
    {
        ft_multiple_moves_node_greater(&node, &target_node, &lists->list_a, &lists->list_b,
            instructions);
        ft_single_move_node_greater(&node, &target_node, &lists->list_a, &lists->list_b,
            instructions);
    }
    ft_swap_pa(&lists->list_a, &lists->list_b, 0, instructions);
}

void	ft_push_to_b(t_list **list_a, t_list **list_b, int total_size,
		char **instructions)
{
	while (ft_lstsize(*list_b) < 2 && ft_lstsize(*list_a) > 3)
	{
		if ((*list_a)->group == 1)
			ft_swap_pb(list_a, list_b, 0, instructions);
		else if ((*list_a)->group == 2)
		{
			ft_swap_pb(list_a, list_b, 0, instructions);
			if (ft_lowest_group(list_b) == 1)
				ft_swap_rb(list_b, 0, 0, instructions);
		}
		else
			ft_swap_ra(list_a, 0, 0, instructions);
	}
	while ((ft_lstsize(*list_a)) > 3)
		ft_pb_by_three_groups(list_a, list_b, total_size, instructions);
}
