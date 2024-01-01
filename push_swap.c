/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2024/01/01 19:52:03 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_by_group(t_list **list_a, t_list **list_b, char **instructions)
{
	int	lowest_group;

	lowest_group = ft_lowest_group(list_a);
	if (lowest_group == ft_highest_group(list_a))
		ft_swap_pb(list_a, list_b, 0, instructions);
	else if ((*list_a)->group == lowest_group
		|| (*list_a)->group == lowest_group + 1)
	{
		ft_swap_pb(list_a, list_b, 0, instructions);
		if ((*list_b)->group == lowest_group + 1
			&& (*list_a)->group == lowest_group + 2)
			ft_swap_rr(list_a, list_b, 0, instructions);
		else if ((*list_b)->group != lowest_group)
			ft_swap_rb(list_b, 0, 0, instructions);
	}
	else if ((*list_a)->group >= lowest_group + 2)
	{
		if ((*list_b)->group == lowest_group + 1)
			ft_swap_rr(list_a, list_b, 0, instructions);
		else
			ft_swap_ra(list_a, 0, 0, instructions);
	}
}

void	ft_pb_by_three_groups(t_list **list_a, t_list **list_b, int total_size,
		char **instructions)
{
	static int	multiplier = 1;
	int			groups;

	groups = ft_highest_group(list_a);
	if (multiplier > ft_highest_group(list_a))
	{
		multiplier = 1;
	}
	while (ft_lstsize(*list_b) <= (total_size * multiplier) / groups
		&& ft_lstsize(*list_a) > 3 && multiplier < 7)
	{
		ft_push_by_group(list_a, list_b, instructions);
	}
	multiplier++;
}

char	*ft_push_swap(t_list **list_a, int iteration)
{
	t_list	*list_b;
	t_list	*node_to_push;
	t_list	*target_node;
	int		total_size;
	char	*instrucs;

	instrucs = NULL;
	total_size = ft_lstsize(*list_a);
	list_b = NULL;
	while (--iteration > 0)
		ft_swap_ra(list_a, 0, 0, &instrucs);
	ft_push_to_b(list_a, &list_b, total_size, &instrucs);
	ft_three_sort_a(list_a, &instrucs);
	while (ft_lstsize(list_b) > 0)
	{
		node_to_push = ft_best_push_pa(&list_b, list_a,
				ft_highest_group(&list_b));
		target_node = ft_get_node(list_a, ft_define_target_pos_pa(node_to_push,
					list_a));
		ft_push_to_a(node_to_push, target_node, list_a, &list_b, &instrucs);
	}
	return (ft_final_sort(list_a, &instrucs), ft_free_list(&list_b), instrucs);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	char	*best_instructions;

	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
	// Virer de la
	if (ac > 2)
	{
		list_a = ft_make_list(ac, av);
		if (!list_a)
			exit(0);
	}
	else
	{
		list_a = ft_make_list(ac, ft_split(av[1], ' '));
		if (!list_a)
			return (0);
	}
	// a la
	if (ft_already_sorted(&list_a))
		return (ft_free_list(&list_a), 0);
	else
	{
		ft_index_list(&list_a);
		best_instructions = ft_brute_force(list_a, 0);
		if (!best_instructions)
			return (ft_free_list(&list_a), 0);
	}
	printf("%s", best_instructions);
	return (ft_free_list(&list_a), free(best_instructions), 0);
}
