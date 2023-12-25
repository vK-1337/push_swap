/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:09:53 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/25 16:48:44 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_already_sorted(t_list **list)
{
	t_list	*curr;

	curr = *list;
	while (curr->next != NULL)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	ft_three_sort_a(t_list **list_a)
{
	int	max_position;

	max_position = ft_find_lst_max_pos(list_a);
	if (max_position == 1)
	{
		ft_swap_ra(list_a, 0);
		if (!ft_already_sorted(list_a))
			ft_swap_a(list_a);
	}
	if (max_position == 2)
	{
		ft_swap_rra(list_a, 0);
		if (!ft_already_sorted(list_a))
			ft_swap_a(list_a);
	}
	else
	{
		if (!ft_already_sorted(list_a))
			ft_swap_a(list_a);
	}
}

void	ft_final_sort(t_list **list_a)
{
	t_list	*min_node;

	min_node = ft_get_node(list_a, ft_find_lst_min_pos(list_a));
	if (min_node->position < ft_lstsize(*list_a) / 2)
	{
		while (min_node->position > 1)
			ft_swap_ra(list_a, 0);
	}
	else
	{
		while (min_node->position != 1)
			ft_swap_rra(list_a, 0);
	}
}
