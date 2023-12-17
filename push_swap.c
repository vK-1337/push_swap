/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/17 20:10:49 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_execute_moves(t_list **list_a, t_list **list_b, t_target_info positions)
{
  // Creer ft_multiple_moves(int *a_node_pos, int *b_node_pos, t_list **list_a, t_list **list_b);
  // Creer ft_move_a(int *a_node_pos, t_list **list_a);
  // Creer ft_move_b(int *b_node_pos, t_list **list_b);
}

void	ft_sort(t_list **list_a)
{
	t_list			**list_b;
	t_target_info	positions;

	if (ft_lstsize(*list_a) == 3)
		ft_three_sort_a(list_a);
	list_b = malloc(sizeof(t_list *));
	ft_swap_pb(list_a, list_b);
	ft_swap_pb(list_a, list_b);
	while (ft_lstsize(*list_a) != 3)
	{
		positions = ft_cheapest_moves(list_a, list_b);
		ft_execute_moves(list_a, list_b, positions);
	}
	ft_three_sort_a(*list_a);
	while (ft_lstsize(list_b) > 0)
	{
		positions = ft_cheapest_moves(list_b, list_a);
		ft_execute_moves(list_b, list_a, positions);
	}
}

int	ft_best_pos(int actual_target_pos, int potential_target_pos,
		t_list **list_b)
{
	int	list_size;
	int	actual_tar_moves;
	int	potential_tar_moves;

	actual_tar_moves = 0;
	list_size = ft_lstsize(*list_b);
	if (actual_target_pos < list_size / 2)
		actual_tar_moves = actual_target_pos - 1;
	else
		actual_tar_moves = (list_size - actual_tar_moves) + 1;
	if (potential_target_pos < list_size / 2)
		potential_tar_moves = potential_target_pos - 1;
	else
		potential_tar_moves = (list_size - actual_tar_moves) + 1;
	if (potential_tar_moves > actual_tar_moves)
		return (actual_target_pos);
	else
		return (potential_target_pos);
}

int	ft_less_than_min(t_list *a_list_node, t_list **list_b)
{
	int		i;
	t_list	*curr;
	int		min_position;

	i = 1;
	curr = *list_b;
	min_position = ft_find_lst_min(list_b);
	while (i != min_position)
	{
		curr = curr->next;
		i++;
	}
	if (a_list_node->content < curr->content)
		return (1);
	return (0);
}

int	ft_get_target(t_list *a_list_node, t_list **list_b)
{
	int		target_position;
	int		content_diff;
	t_list	*curr;
	int		i;

	curr = *list_b;
	target_position = 1;
	i = 1;
	content_diff = ft_content_diff(a_list_node, curr);
	while (curr->next != NULL)
	{
		if ((ft_content_diff(a_list_node, curr)) <= content_diff)
		{
			target_position = ft_best_pos(target_position, i, list_b);
			content_diff = a_list_node->content - curr->content;
		}
		i++;
		curr = curr->next;
	}
	if ((ft_content_diff(a_list_node, curr)) <= content_diff)
	{
		target_position = ft_best_pos(target_position, ++i, list_b);
		content_diff = a_list_node->content - curr->content;
	}
	return (target_position);
}

int	ft_content_diff(t_list *a_list_node, t_list *b_list_node)
{
	int	content_diff;

	content_diff = a_list_node->content - b_list_node->content;
	if (content_diff < 0)
		content_diff *= -1;
	return (content_diff);
}

t_target_info	ft_cheapest_moves(t_list **list_a, t_list **list_b)
{
	int				i;
	int				cost;
	int				target_position;
	t_list			*curr_a;
	t_target_info	insertion_info;

	curr_a = *list_a;
	i = 1;
	target_position = ft_get_target(curr_a, list_b);
	cost = ft_cost(i, target_position, list_a, list_b);
	insertion_info.target_pos = target_position;
	insertion_info.pos_to_insert = i;
	while (curr_a != NULL)
	{
		target_position = ft_get_target(curr_a, list_b);
		if (ft_cost(i, target_position, list_a, list_b) < cost)
		{
			insertion_info.target_pos = target_position;
			insertion_info.pos_to_insert = i;
			cost = ft_cost(i, target_position, list_a, list_b);
		}
		i++;
		curr_a = curr_a->next;
	}
	return (insertion_info);
}

int	ft_push_swap(int ac, char **av)
{
	t_list	**list_a;

	list_a = malloc(sizeof(t_list *));
	if (ac > 2)
		*list_a = ft_make_list(av, ac);
	else
		*list_a = ft_make_list(ft_split(av[1], ' '), ac);
	if (ft_already_sorted(list_a))
		return (0);
	ft_sort(list_a);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
	ft_push_swap(ac, av);
	return (0);
}
