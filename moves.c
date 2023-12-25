/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:38:03 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/25 20:35:53 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_to_a(t_list *node, t_list *target_node, t_list **list_a, t_list **list_b)
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
