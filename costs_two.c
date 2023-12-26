/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:29:25 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/26 12:53:24 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_cost_greater_node(int *node_position, int *target_position,
		int *cost, t_costs_info infos)
{
	int	node_list_size;
	int	target_list_size;

	node_list_size = infos.node_list_size;
	target_list_size = infos.target_list_size;
	if (*node_position < node_list_size / 2
		&& *target_position < target_list_size / 2)
		*cost = multiple_rotates_up_greater(node_position, target_position,
				cost);
	else if (*node_position >= node_list_size / 2
		&& *target_position >= target_list_size / 2)
		*cost = multiple_rotates_down_greater(node_position, target_position,
				cost, infos);
	if (*node_position < node_list_size / 2)
		*cost = single_rotate_cost(node_position, 1, cost);
	else
		*cost = single_rotate_cost(node_position, node_list_size, cost);
	if (*target_position < node_list_size / 2)
		*cost = single_rotate_cost(target_position, 1, cost);
	else
		*cost = single_rotate_cost(target_position, target_list_size, cost);
	return (*cost);
}

int	ft_get_cost_lower_node(int *node_position, int *target_position, int *cost,
		t_costs_info infos)
{
	int	node_list_size;
	int	target_list_size;

	node_list_size = infos.node_list_size;
	target_list_size = infos.target_list_size;
	if (*node_position < node_list_size / 2
		&& *target_position < target_list_size / 2)
		*cost = multiple_rotates_up_lower(node_position, target_position, cost);
	else if (*node_position >= node_list_size / 2
		&& *target_position >= target_list_size / 2)
		*cost = multiple_rotates_down_lower(node_position, target_position,
				cost, infos);
	if (*node_position < node_list_size / 2)
		*cost = single_rotate_cost(node_position, 1, cost);
	else
		*cost = single_rotate_cost(node_position, node_list_size + 1, cost);
	if (*target_position < node_list_size / 2)
		*cost = single_rotate_cost(target_position, 0, cost);
	else
		*cost = single_rotate_cost(target_position, target_list_size, cost);
	return (*cost);
}

int	ft_get_cost_pa(t_list node, t_list target, t_list **node_list,
		t_list **target_list)
{
	int				node_position;
	int				target_position;
	int				cost;
	t_costs_info	infos;

	cost = 0;
	node_position = node.position;
	target_position = target.position;
	infos.node_list_size = ft_lstsize(*node_list);
	infos.target_list_size = ft_lstsize(*target_list);
	if (node.content > target.content)
		cost = ft_get_cost_greater_node(&node_position, &target_position, &cost,
				infos);
	else
		cost = ft_get_cost_lower_node(&node_position, &target_position, &cost,
				infos);
	return (cost);
}

t_list	*ft_best_push_pa(t_list **from_list, t_list **to_list)
{
	t_list	*curr;
	t_list	*best_node;
	int		curr_cost;
	int		best_cost;

	curr = *from_list;
	best_cost = ft_get_cost_pa(*curr, *ft_get_node(to_list,
				ft_get_closer_target(curr, to_list)), from_list, to_list);
	best_node = curr;
	while (curr)
	{
		curr_cost = ft_get_cost_pa(*curr, *ft_get_node(to_list,
					ft_get_closer_target(curr, to_list)), from_list, to_list);
		if (curr_cost < best_cost)
		{
			best_cost = curr_cost;
			best_node = curr;
		}
		curr = curr->next;
	}
	return (best_node);
}
