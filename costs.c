/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:40:19 by vk                #+#    #+#             */
/*   Updated: 2023/12/26 12:29:45 by vda-conc         ###   ########.fr       */
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

int	multiple_rotates_down_greater(int *position1, int *position2, int *cost,
		t_costs_info infos)
{
	while (*position1 <= infos.node_list_size
		&& *position2 <= infos.target_list_size)
	{
		(*position1)++;
		(*position2)++;
		(*cost)++;
	}
	return (*cost);
}

int	multiple_rotates_down_lower(int *position1, int *position2, int *cost,
		t_costs_info infos)
{
	while (*position1 <= infos.node_list_size
		&& *position2 < infos.target_list_size)
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


