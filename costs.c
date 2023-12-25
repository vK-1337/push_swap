/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:40:19 by vk                #+#    #+#             */
/*   Updated: 2023/12/25 19:56:47 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_cost_pa(t_list node, t_list target, t_list **node_list,
		t_list **target_list)
{
	t_costs_info	infos;
	int				cost;

	cost = 0;
	infos.node_position = node.position;
	infos.target_position = target.position;
	infos.node_list_size = ft_lstsize(*node_list);
	infos.target_list_size = ft_lstsize(*target_list);
	if (node.content > target.content)
	{
		ft_multiple_rotate_cost_greater(infos, &cost);
		ft_single_rotate_cost_greater(infos, &cost);
	}
	else
	{
		ft_multiple_rotate_cost_lesser(infos, &cost);
		ft_single_rotate_cost_lesser(infos, &cost);
	}
	return (cost);
}

void	ft_multiple_rotate_cost_lesser(t_costs_info infos, int *cost)
{
	if (infos.node_position < infos.node_list_size / 2
		&& infos.target_position < infos.target_list_size / 2)
  {
		while (infos.node_position-- > 1 && infos.target_position-- >= 1)
			(*cost)++;
  }
	else if (infos.node_position >= infos.node_list_size / 2
		&& infos.target_position >= infos.target_list_size / 2)
    {
		while (infos.node_position++ != infos.node_list_size + 1
			&& infos.target_position++ != infos.target_list_size)
			(*cost)++;
    }
}

void	ft_multiple_rotate_cost_greater(t_costs_info infos, int *cost)
{
	if (infos.node_position < infos.node_list_size / 2
		&& infos.target_position < infos.target_list_size / 2)
  {
		while (infos.node_position-- > 1 && infos.target_position-- > 1)
			(*cost)++;
  }
	else if (infos.node_position >= infos.node_list_size / 2
		&& infos.target_position >= infos.target_list_size / 2)
	{
		while (infos.node_position++ != infos.node_list_size + 1
			&& infos.target_position++ != infos.target_list_size + 1)
			(*cost)++;
	}
}

void	ft_single_rotate_cost_greater(t_costs_info infos, int *cost)
{
	if (infos.node_position < infos.node_list_size / 2)
		{
      while (infos.node_position-- > 1)
			(*cost)++;
    }
  else
    {
      while (infos.node_position++ != infos.node_list_size + 1)
        (*cost)++;
    }
	if (infos.target_position < infos.node_list_size / 2)
  {
		while (infos.target_position-- > 1)
			(*cost)++;
  }
	else
  {
		while (infos.target_position++ != infos.target_list_size + 1)
			(*cost)++;
  }
}

void	ft_single_rotate_cost_lesser(t_costs_info infos, int *cost)
{
	if (infos.node_position < infos.node_list_size / 2)
  {
		while (infos.node_position-- > 1)
			(*cost)++;
  }
	else
  {
		while (infos.node_position++ != infos.node_list_size + 1)
			(*cost)++;
  }
	if (infos.target_position < infos.node_list_size / 2)
  {
		while (infos.target_position-- >= 1)
			(*cost)++;
  }
	else
  {
		while (infos.target_position++ != infos.target_list_size)
			(*cost)++;
  }
}
