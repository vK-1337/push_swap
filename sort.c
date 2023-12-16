/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:09:53 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/16 01:05:37 by vda-conc         ###   ########.fr       */
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

	max_position = ft_find_lst_max(list_a);
	if (max_position == 1)
	{
		ft_swap_ra(list_a);
		if (!ft_already_sorted(list_a))
			ft_swap_a(list_a);
	}
	if (max_position == 2)
	{
		ft_swap_rra(list_a);
		if (!ft_already_sorted(list_a))
			ft_swap_a(list_a);
	}
	else
	{
		if (!ft_already_sorted(list_a))
			ft_swap_a(list_a);
	}
}
