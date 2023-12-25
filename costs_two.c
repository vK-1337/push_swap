/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:35:56 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/25 19:36:16 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
