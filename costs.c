/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:40:19 by vk                #+#    #+#             */
/*   Updated: 2023/12/17 19:30:59 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost(int a_node_pos, int b_node_pos, t_list **list_a, t_list **list_b)
{
	int	cost;
	int	list_a_size;
	int	list_b_size;

	list_a_size = ft_lstsize(*list_a);
	list_b_size = ft_lstsize(*list_b);
	cost = 0;
	ft_multiple_costs(&cost, &a_node_pos, &b_node_pos, list_a_size,
		list_b_size);
	ft_single_cost_a(&cost, &a_node_pos, list_a_size);
	ft_single_cost_b(&cost, &b_node_pos, list_b_size);
	return (cost);
}

void	ft_single_cost_a(int *cost, int *a_node_pos, int a_size)
{
	if (*a_node_pos > a_size / 2)
	{
		while (*a_node_pos <= a_size)
		{
			(*a_node_pos)++;
			(*cost)++;
		}
	}
	if (*a_node_pos < a_size / 2)
	{
		while (*a_node_pos >= 1)
		{
			(*a_node_pos)--;
			(*cost)++;
		}
	}
}

void	ft_single_cost_b(int *cost, int *b_node_pos, int b_size)
{
	if (*b_node_pos > b_size / 2)
	{
		while (*b_node_pos <= b_size)
		{
			(*b_node_pos)++;
			(*cost)++;
		}
	}
	if (*b_node_pos < b_size / 2)
	{
		while (*b_node_pos >= 1)
		{
			(*b_node_pos)--;
			(*cost)++;
		}
	}
}

void	ft_multiple_costs(int *cost, int *a_node_pos, int *b_node_pos,
		int a_size, int b_size)
{
	if ((*a_node_pos > a_size / 2) && (*a_node_pos > b_size / 2))
	{
		while (*a_node_pos <= a_size && *b_node_pos <= b_size)
		{
			(*a_node_pos)++;
			(*b_node_pos)++;
			(*cost)++;
		}
	}
	if ((*a_node_pos < a_size / 2) && (*b_node_pos < b_size / 2))
	{
		while (*a_node_pos >= 1 && *b_node_pos >= 1)
		{
			(*a_node_pos)--;
			(*b_node_pos)--;
			(*cost)++;
		}
	}
}
