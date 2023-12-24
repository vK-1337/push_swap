/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/24 19:18:18 by vk               ###   ########.fr       */
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

void ft_push_a_node(t_list *node, t_list *target_node, t_list **list_a, t_list **list_b)
{
  int node_list_size;
  int target_list_size;
  t_list *list_min;
  t_list *list_max;
  int target_is_max;

  list_min = ft_get_node(list_b, ft_find_lst_min_pos(list_b));
  list_max = ft_get_node(list_b, ft_find_lst_max_pos(list_b));
  node_list_size = ft_lstsize(*list_a);
  target_list_size = ft_lstsize(*list_b);
  target_is_max = 0;
  if (node->content > list_max->content || node->content < list_min->content)
    target_is_max = 1;
  if (node->content > target_node->content || target_is_max == 1)
  {
    // Multiple rotates
    if (node->position < node_list_size / 2 && target_node->position < target_list_size / 2)
    {
      while (node->position > 1 && target_node->position > 1)
      {
        ft_swap_rr(list_a, list_b);
      }
    }
    else if (node->position >= node_list_size / 2 && target_node->position >= target_list_size / 2)
    {
      while (node->position != 1 && target_node->position != 1)
      {
        ft_swap_rrr(list_a, list_b);
      }
    }
    // Single rotates
    // Rotate A
    if (node->position < node_list_size / 2)
    {
      while (node->position > 1)
      {
        ft_swap_ra(list_a, 0);
      }
    }
    else
    {
      while (node->position != 1)
      {
        ft_swap_rra(list_a, 0);
      }
    }
    // Rotate B
    if ( target_node->position < node_list_size / 2)
    {
      while (target_node->position > 1)
      {
        ft_swap_rb(list_b, 0);
      }
    }
    else
    {
      while (target_node->position != 1)
      {
        ft_swap_rrb(list_b, 0);
      }
    }
  }
  else
  {
    if (node->position < node_list_size / 2 && target_node->position < target_list_size / 2)
    {
      while (node->position > 1 && target_node->position != target_list_size)
      {
        ft_swap_rr(list_a, list_b);
      }
    }
    else if (node->position >= node_list_size / 2 && target_node->position >= target_list_size / 2)
    {
      while (node->position != 1 && target_node->position != target_list_size)
      {
        ft_swap_rrr(list_a, list_b);
      }
    }
    // Single rotates
    // Rotate A
    if (node->position < node_list_size / 2)
    {
      while (node->position > 1)
      {
        ft_swap_ra(list_a, 0);
      }
    }
    else
    {
      while (node->position != 1)
      {
        ft_swap_rra(list_a, 0);
      }
    }
    // Rotate B
    if (target_node->position < target_list_size / 2)
    {
      while (target_node->position != target_list_size)
      {
        ft_swap_rb(list_b, 0);
      }
    }
    else
    {
      while (target_node->position != target_list_size)
      {
        ft_swap_rrb(list_b, 0);
      }
    }
  }
  ft_swap_pb(list_a, list_b);
}

void ft_push_b_node(t_list *node, t_list *target_node, t_list **list_a, t_list **list_b)
{
  int node_list_size;
  int target_list_size;
  t_list *list_min;
  t_list *list_max;
  int target_is_min;

  list_min = ft_get_node(list_a, ft_find_lst_min_pos(list_a));
  list_max = ft_get_node(list_a, ft_find_lst_max_pos(list_a));
  node_list_size = ft_lstsize(*list_b);
  target_list_size = ft_lstsize(*list_a);

  target_is_min = 0;
  if (node->content > list_max->content || node->content < list_min->content)
    target_is_min = 1;
  if (node->content < target_node->content || target_is_min == 1)
  {
    if (node->position < node_list_size / 2 && target_node->position < target_list_size / 2)
    {
      while (node->position > 1 && target_node->position > 1)
      {
        ft_swap_rr(list_a, list_b);
      }
    }
    else if (node->position >= node_list_size / 2 && target_node->position >= target_list_size / 2)
    {
      while (node->position != 1 && target_node->position != 1)
      {
        ft_swap_rrr(list_a, list_b);
      }
    }
    // Single rotates
    // Rotate B
    if (node->position < node_list_size / 2)
    {
      while (node->position > 1)
      {
        ft_swap_rb(list_b, 0);
      }
    }
    else
    {
      while (node->position != 1)
      {
        ft_swap_rrb(list_b, 0);
      }
    }
    // Rotate A
    if (target_node->position < target_list_size / 2)
    {
      while (target_node->position > 1)
      {
        ft_swap_ra(list_a, 0);
      }
    }
    else
    {
      while (target_node->position != 1)
      {
        ft_swap_rra(list_a, 0);
      }
    }
  }
  else
  {
    if (node->position < node_list_size / 2 && target_node->position < target_list_size / 2)
    {
      while (node->position > 1 && target_node->position != target_list_size)
      {
        ft_swap_rr(list_a, list_b);
      }
    }
    else if (node->position >= node_list_size / 2 && target_node->position >= target_list_size / 2)
    {
      while (node->position != 1 && target_node->position != target_list_size)
      {
        ft_swap_rrr(list_a, list_b);
      }
    }
    // Single rotates
    // Rotate A
    if (node->position < node_list_size / 2)
    {
      while (node->position > 1)
      {
        ft_swap_rb(list_b, 0);
      }
    }
    else
    {
      while (node->position != 1)
      {
        ft_swap_rrb(list_b, 0);
      }
    }
    // Rotate B
    if (target_node->position < target_list_size / 2)
    {
      while (target_node->position != target_list_size)
      {
        ft_swap_ra(list_a, 0);
      }
    }
    else
    {
      while (target_node->position != target_list_size)
      {
        ft_swap_rra(list_a, 0);
      }
    }
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
	while (ft_lstsize(*list_a) > 3 && ft_lstsize(list_b) < 2)
		ft_swap_pb(list_a, &list_b);
	while (ft_lstsize(*list_a) > 3)
	{
		node_to_push = ft_best_push_pb(list_a, &list_b);
    target_node = ft_get_node(&list_b, ft_define_target_pos(node_to_push, &list_b));
    ft_push_a_node(node_to_push, target_node, list_a, &list_b);
  }
  ft_three_sort_a(list_a);
  while (ft_lstsize(list_b) > 0)
  {
    node_to_push = ft_best_push_pb(&list_b, list_a);
    target_node = ft_get_node(list_a, ft_define_target_pos_pb(node_to_push, list_a));
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
