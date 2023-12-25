/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/25 23:28:12 by vk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_final_sort(t_list **list_a)
{
  t_list *min_node;

  min_node = ft_get_node(list_a, ft_find_lst_min_pos(list_a));
  if ( min_node->position < ft_lstsize(*list_a) / 2)
  {
    while (min_node->position > 1)
    {
      ft_swap_ra(list_a, 0);
    }
  }
  else
  {
    while (min_node->position != 1)
    {
      ft_swap_rra(list_a, 0);
    }
  }
}

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
void	ft_multiple_moves_node_lesser(t_list **node, t_list **target_node,
		t_list **list_a, t_list **list_b)
{
	int	node_list_size;
	int	target_list_size;

	node_list_size = ft_lstsize(*list_b);
	target_list_size = ft_lstsize(*list_a);
	if ((*node)->position < node_list_size / 2
		&& (*target_node)->position < target_list_size / 2)
	{
		while ((*node)->position > 1 && (*target_node)->position > 1)
			ft_swap_rr(list_a, list_b);
	}
	else if ((*node)->position >= node_list_size / 2
		&& (*target_node)->position >= target_list_size / 2)
	{
		while ((*node)->position != 1 && (*target_node)->position != 1)
			ft_swap_rrr(list_a, list_b);
	}
}

void	ft_single_move_node_lesser(t_list **node, t_list **target_node,
		t_list **list_a, t_list **list_b)
{
	int	node_list_size;
	int	target_list_size;

	node_list_size = ft_lstsize(*list_b);
	target_list_size = ft_lstsize(*list_a);
	if ((*node)->position < node_list_size / 2)
	{
		while ((*node)->position > 1)
			ft_swap_rb(list_b, 0);
	}
	else
	{
		while ((*node)->position != 1)
			ft_swap_rrb(list_b, 0);
	}
	if ((*target_node)->position < target_list_size / 2)
	{
		while ((*target_node)->position > 1)
			ft_swap_ra(list_a, 0);
	}
	else
	{
		while ((*target_node)->position != 1)
			ft_swap_rra(list_a, 0);
	}
}
void	ft_multiple_moves_node_greater(t_list **node, t_list **target_node,
		t_list **list_a, t_list **list_b)
{
	int	node_list_size;
	int	target_list_size;

	node_list_size = ft_lstsize(*list_b);
	target_list_size = ft_lstsize(*list_a);
	if ((*node)->position < node_list_size / 2
		&& (*target_node)->position < target_list_size / 2)
	{
		while ((*node)->position > 1 && (*target_node)->position != target_list_size)
			ft_swap_rr(list_a, list_b);
	}
	else if ((*node)->position >= node_list_size / 2
		&& (*target_node)->position >= target_list_size / 2)
	{
		while ((*node)->position != 1 && (*target_node)->position != target_list_size)
			ft_swap_rrr(list_a, list_b);
	}
}

void	ft_single_move_node_greater(t_list **node, t_list **target_node,
		t_list **list_a, t_list **list_b)
{
	int	node_list_size;
	int	target_list_size;

	node_list_size = ft_lstsize(*list_b);
	target_list_size = ft_lstsize(*list_a);
	if ((*node)->position < node_list_size / 2)
	{
		while ((*node)->position > 1)
			ft_swap_rb(list_b, 0);
	}
	else
	{
		while ((*node)->position != 1)
			ft_swap_rrb(list_b, 0);
	}
	if ((*target_node)->position < target_list_size / 2)
	{
		while ((*target_node)->position != target_list_size)
			ft_swap_ra(list_a, 0);
	}
	else
	{
		while ((*target_node)->position != target_list_size)
			ft_swap_rra(list_a, 0);
	}
}

void ft_push_b_node(t_list *node, t_list *target_node, t_list **list_a, t_list **list_b)
{
  t_list *list_min;
  t_list *list_max;
  int target_is_min;

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
  ft_swap_pa(list_a, list_b);
}

void ft_push_swap(t_list **list_a)
{
	t_list *list_b;
	t_list *node_to_push;
  t_list *target_node;

	list_b = malloc(sizeof (t_list *));
  list_b = NULL;
	ft_push_to_b(list_a, &list_b);
  ft_three_sort_a(list_a);
  while (ft_lstsize(list_b) > 0)
  {
    node_to_push = ft_best_push_pa(&list_b, list_a);
    target_node = ft_get_node(list_a, ft_define_target_pos_pa(node_to_push, list_a));
    ft_push_b_node(node_to_push, target_node, list_a, &list_b);
  }
  ft_final_sort(list_a);
}

int	main(int ac, char **av)
{
	t_list *list_a;

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
