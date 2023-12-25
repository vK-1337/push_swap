/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/25 20:14:49 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_b(t_list **list_a, t_list **list_b)
{
	int	total_size;

	total_size = ft_lstsize(*list_a);
	while (ft_lstsize(*list_a) > 3 && ft_lstsize(*list_b) < total_size / 3
		&& total_size > 100)
	{
		if ((*list_a)->index <= total_size / 3)
			ft_swap_pb(list_a, list_b);
		else
			ft_swap_ra(list_a, 0);
	}
	while (ft_lstsize(*list_a) > 3 && ft_lstsize(*list_b) < total_size / 2)
	{
		if ((*list_a)->index <= total_size / 2)
			ft_swap_pb(list_a, list_b);
		else
			ft_swap_ra(list_a, 0);
	}
	while (ft_lstsize(*list_a) > 3)
		ft_swap_pb(list_a, list_b);
}

void	ft_push_swap(t_list **list_a)
{
	t_list	*list_b;
	t_list	*node_to_push;
	t_list	*target_node;

	list_b = NULL;
	ft_push_to_b(list_a, &list_b);
	ft_three_sort_a(list_a);
	while (ft_lstsize(list_b) > 0)
	{
		node_to_push = ft_best_push_pa(&list_b, list_a);
		target_node = ft_get_node(list_a, ft_define_target_pos_pb(node_to_push,
					list_a));
		ft_push_to_a(node_to_push, target_node, list_a, &list_b);
	}
	ft_final_sort(list_a);
	return ;
}

int	main(int ac, char **av)
{
	t_list	*list_a;

	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
	if (ac > 2)
		list_a = ft_make_list(ac, av);
	else
		list_a = ft_make_list(ac, ft_split(av[1], ' '));
	if (ft_already_sorted(&list_a))
		return (0);
	else
	{
		ft_index_list(&list_a);
		ft_push_swap(&list_a);
	}
	return (0);
}
