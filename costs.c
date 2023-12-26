/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:40:19 by vk                #+#    #+#             */
/*   Updated: 2023/12/26 11:38:26 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	multiple_rotates_up_greater(int *position1, int *position2, int *cost)
{
	while (*position1 > 1 && *position2 > 1)
	{
		(*position1)--;
		(*position2)--;
		(*cost)++;
	}
	return (*cost);
}

int	multiple_rotates_up_lower(int *position1, int *position2, int *cost)
{
	while (*position1 > 1 && *position2 > 0)
	{
		(*position1)--;
		(*position2)--;
		(*cost)++;
	}
	return (*cost);
}

int multiple_rotates_down_greater(int *position1, int *position2, int *cost, t_costs_info infos)
{
	while (*position1 <= infos.node_list_size && *position2 <= infos.target_list_size)
	{
		(*position1)++;
		(*position2)++;
		(*cost)++;
	}
	return (*cost);
}

int multiple_rotates_down_lower(int *position1, int *position2, int *cost, t_costs_info infos)
{
	while (*position1 <= infos.node_list_size && *position2 < infos.target_list_size)
	{
		(*position1)++;
		(*position2)++;
		(*cost)++;
	}
	return (*cost);
}

int	single_rotate_cost(int *position, int limit, int *cost)
{
	while (*position != limit)
	{
		if (*position < limit)
			(*position)++;
		else
			(*position)--;
		(*cost)++;
	}
	return (*cost);
}


int	ft_get_cost_pa(t_list node, t_list target, t_list **node_list,
		t_list **target_list)
{
	int	node_position;
	int	target_position;
	int	node_list_size;
	int	target_list_size;
	int	cost;
	t_costs_info infos;

	cost = 0;
	node_position = node.position;
	target_position = target.position;
	node_list_size = ft_lstsize(*node_list);
	target_list_size = ft_lstsize(*target_list);
	infos.node_list_size = node_list_size;
	infos.target_list_size = target_list_size;
	if (node.content > target.content)
	{
		if (node_position < node_list_size / 2
			&& target_position < target_list_size / 2)
			cost = multiple_rotates_up_greater(&node_position, &target_position, &cost);
		else if (node_position >= node_list_size / 2
			&& target_position >= target_list_size / 2)
			cost = multiple_rotates_down_greater(&node_position, &target_position, &cost, infos);
		if (node_position < node_list_size / 2)
			cost = single_rotate_cost(&node_position, 1, &cost);
		else
			cost = single_rotate_cost(&node_position, node_list_size, &cost);
		if (target_position < node_list_size / 2)
			cost = single_rotate_cost(&target_position, 1, &cost);
		else
			cost = single_rotate_cost(&target_position, target_list_size, &cost);
	}
	else
	{
		if (node_position < node_list_size / 2
			&& target_position < target_list_size / 2)
			cost = multiple_rotates_up_lower(&node_position, &target_position, &cost);
		else if (node_position >= node_list_size / 2
			&& target_position >= target_list_size / 2)
			cost = multiple_rotates_down_lower(&node_position, &target_position, &cost, infos);
		if (node_position < node_list_size / 2)
			cost = single_rotate_cost(&node_position, 1, &cost);
		else
			cost = single_rotate_cost(&node_position, node_list_size + 1, &cost);
		// Rotate B
		if (target_position < node_list_size / 2)
			cost = single_rotate_cost(&target_position, 0, &cost);
		else
			cost = single_rotate_cost(&target_position, target_list_size, &cost);
	}
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
	while (curr->next)
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
	curr_cost = ft_get_cost_pa(*curr, *ft_get_node(to_list,
				ft_get_closer_target(curr, to_list)), from_list, to_list);
	if (curr_cost < best_cost)
	{
		best_cost = curr_cost;
		best_node = curr;
	}
	return (best_node);
}
