/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/29 18:52:24 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list **list)
{
	t_list	*curr;
	int		i;

	if (!(*list))
		return ;
	curr = *list;
	i = 1;
	while (curr)
	{
		// printf("Adresse du node %d |%p|\n", i, curr);
		printf("Contenu du node %d  |%d|\n", i, curr->content);
		// printf("Contenu du node %d ->next |%p|\n", i, curr->next);
		// printf("Contenu de node %d ->prev |%p|\n", i, curr->prev);
		printf("Index => |%d|\n", curr->index);
		printf("Position => |%d|\n", curr->position);
    printf("Group => |%d|\n", curr->group);
		curr = curr->next;
		i++;
	}
}

void	ft_final_sort(t_list **list_a)
{
	t_list	*min_node;

	min_node = ft_get_node(list_a, ft_find_lst_min_pos(list_a));
	if (min_node->position < ft_lstsize(*list_a) / 2)
	{
		while (min_node->position > 1)
		{
			ft_swap_ra(list_a, 0, 0);
		}
	}
	else
	{
		while (min_node->position != 1)
		{
			ft_swap_rra(list_a, 0, 0);
		}
	}
}

void	ft_push_to_b(t_list **list_a, t_list **list_b, int total_size,
		int groups)
{
	while (ft_lstsize(*list_b) < 2 && ft_lstsize(*list_a) > 3)
	{
		if ((*list_a)->group == 1)
			ft_swap_pb(list_a, list_b, 0);
		else if ((*list_a)->group == 2)
		{
			ft_swap_pb(list_a, list_b, 0);
			if (ft_lowest_group(list_b) == 1)
				ft_swap_rb(list_b, 0, 0);
		}
		else
				ft_swap_ra(list_a, 0, 0);
	}
	while (ft_lstsize(*list_a) > 3)
		ft_push_by_group(list_a, list_b, groups, total_size);
}

void	ft_push_by_group(t_list **list_a, t_list **list_b, int groups,
		int total_size)
{
	static int	multiplier = 1;
	while (ft_lstsize(*list_b) <= (total_size * multiplier) / groups && ft_lstsize(*list_a) > 3)
	{
		if (ft_lowest_group(list_a) == groups)
		{
			ft_swap_pb(list_a, list_b, 0);
			continue;
		}
		else if ((*list_a)->group == 3)
		{
			if ((*list_b)->group == 2)
				ft_swap_rr(list_a, list_b, 0);
			else
				ft_swap_ra(list_a, 0, 0);
		}
		else if ((*list_a)->group == 2)
		{
			ft_swap_pb(list_a, list_b, 0);
			if ((*list_b)->group == 2 && (*list_a)->group == 3)
				ft_swap_rr(list_a, list_b, 0);
			else
			ft_swap_rb(list_b, 0, 0);
		}
		else if ((*list_a)->group == 1)
			ft_swap_pb(list_a, list_b, 0);
	}
	multiplier++;
}

void	ft_push_to_a(t_list *node, t_list *target_node, t_list **list_a,
		t_list **list_b)
{
	t_list	*list_min;
	t_list	*list_max;
	int		target_is_min;

	list_min = ft_get_node(list_a, ft_find_lst_min_pos(list_a));
	list_max = ft_get_node(list_a, ft_find_lst_max_pos(list_a));
	target_is_min = 0;
	if (node->content > list_max->content || node->content < list_min->content)
		target_is_min = 1;
	if (node->content < target_node->content || target_is_min == 1)
	{
		ft_multiple_moves_node_lesser(&node, &target_node, list_a, list_b);
		ft_single_move_node_lesser(&node, &target_node, list_a, list_b);
	}
	else
	{
		ft_multiple_moves_node_greater(&node, &target_node, list_a, list_b);
		ft_single_move_node_greater(&node, &target_node, list_a, list_b);
	}
	ft_swap_pa(list_a, list_b, 0);
}

void	ft_push_swap(t_list **list_a)
{
	t_list	*list_b;
	t_list	*node_to_push;
	t_list	*target_node;
	int		group;
	int		total_size;

	total_size = ft_lstsize(*list_a);
	group = ft_highest_group(list_a);
	list_b = NULL;
	ft_push_to_b(list_a, &list_b, total_size, group);
	ft_three_sort_a(list_a);
	while (ft_lstsize(list_b) > 0)
	{
		node_to_push = ft_best_push_pa(&list_b, list_a, group);
		target_node = ft_get_node(list_a, ft_define_target_pos_pa(node_to_push,
					list_a));
		ft_push_to_a(node_to_push, target_node, list_a, &list_b);
		group = ft_highest_group(&list_b);
	}
	ft_final_sort(list_a);
}

int	ft_highest_group(t_list **list_b)
{
	t_list	*curr;
	int		highest_group;

	curr = *list_b;
	highest_group = 1;
	while (curr)
	{
		if (curr->group > highest_group)
			highest_group = curr->group;
		curr = curr->next;
	}
	return (highest_group);
}

int	ft_lowest_group(t_list **list)
{
	t_list	*curr;
	int		lowest_group;

	curr = *list;
	lowest_group = curr->group;
	while (curr)
	{
		if (curr->group < lowest_group)
			lowest_group = curr->group;
		curr = curr->next;
	}
	return (lowest_group);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	char	**list;

	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
	if (ac > 2)
		list_a = ft_make_list(ac, av);
	else
	{
		list = ft_split(av[1], ' ');
		list_a = ft_make_list(ac, list);
		ft_free_memory(list);
	}
	if (ft_already_sorted(&list_a))
		return (ft_free_list(&list_a), 0);
	else
	{
		ft_index_list(&list_a);
		ft_push_swap(&list_a);
	}
	// ft_print_list(&list_a);
	return (ft_free_list(&list_a), 0);
}
