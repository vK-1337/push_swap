/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:40:19 by vk                #+#    #+#             */
/*   Updated: 2023/12/25 00:01:17 by vk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_get_cost_pb(t_list node, t_list target, t_list **node_list, t_list **target_list)
{
  int node_position;
  int target_position;
  int node_list_size;
  int target_list_size;
  int cost = 0;

  node_position = node.position;
  target_position = target.position;
  node_list_size = ft_lstsize(*node_list);
  target_list_size = ft_lstsize(*target_list);

  if (node.content > target.content)
  {
    // Multiple rotates
    if (node_position < node_list_size / 2 && target_position < target_list_size / 2)
    {
      while (node_position > 1 && target_position != target_list_size)
      {
        node_position--;
        target_position--;
        cost++;
      }
    }
    else if (node_position >= node_list_size / 2 && target_position >= target_list_size / 2)
    {
      while (node_position != node_list_size + 1 && target_position != target_list_size)
      {
        node_position++;
        target_position++;
        cost++;
      }
    }
    // Single rotates
    // Rotate A
    if (node_position < node_list_size / 2)
    {
      while (node_position > 1)
      {
        node_position--;
        cost++;
      }
    }
    else
    {
      while (node_position != node_list_size + 1)
      {
        node_position++;
        cost++;
      }
    }
    // Rotate B
    if (target_position < node_list_size / 2)
    {
      while (target_position >= 1)
      {
        target_position--;
        cost++;
      }
    }
    else
    {
      while(target_position != target_list_size)
      {
        target_position++;
        cost++;
      }
    }
  }
  else
  {
    // Multiple rotates
    if (node_position < node_list_size / 2 && target_position < target_list_size / 2)
    {
      while (node_position > 1 && target_position > 1)
      {
        node_position--;
        target_position--;
        cost++;
      }
    }
    else if (node_position >= node_list_size / 2 && target_position >= target_list_size / 2)
    {
      while (node_position != node_list_size + 1 && target_position != target_list_size + 1)
      {
        node_position++;
        target_position++;
        cost++;
      }
    }
    // Single rotates
    // Rotate A
    if (node_position < node_list_size / 2)
    {
      while (node_position > 1)
      {
        node_position--;
        cost++;
      }
    }
    else
    {
      while (node_position != node_list_size + 1)
      {
        node_position++;
        cost++;
      }
    }
    // Rotate B
    if (target_position < node_list_size / 2)
    {
      while (target_position > 1)
      {
        target_position--;
        cost++;
      }
    }
    else
    {
      while(target_position != target_list_size + 1)
      {
        target_position++;
        cost++;
      }
    }
  }
  return (cost);
}

int ft_get_cost_pa(t_list node, t_list target, t_list **node_list, t_list **target_list)
{
  int node_position;
  int target_position;
  int node_list_size;
  int target_list_size;
  int cost = 0;

  node_position = node.position;
  target_position = target.position;
  node_list_size = ft_lstsize(*node_list);
  target_list_size = ft_lstsize(*target_list);

  if (node.content > target.content)
  {
    // Multiple rotates
    if (node_position < node_list_size / 2 && target_position < target_list_size / 2)
    {
      while (node_position > 1 && target_position > 1)
      {
        node_position--;
        target_position--;
        cost++;
      }
    }
    else if (node_position >= node_list_size / 2 && target_position >= target_list_size / 2)
    {
      while (node_position != node_list_size + 1 && target_position != target_list_size + 1)
      {
        node_position++;
        target_position++;
        cost++;
      }
    }
    // Single rotates
    // Rotate A
    if (node_position < node_list_size / 2)
    {
      while (node_position > 1)
      {
        node_position--;
        cost++;
      }
    }
    else
    {
      while (node_position != node_list_size + 1)
      {
        node_position++;
        cost++;
      }
    }
    // Rotate B
    if (target_position < node_list_size / 2)
    {
      while (target_position > 1)
      {
        target_position--;
        cost++;
      }
    }
    else
    {
      while(target_position != target_list_size + 1)
      {
        target_position++;
        cost++;
      }
    }
  }
  else
  {
    // Multiple rotates
    if (node_position < node_list_size / 2 && target_position < target_list_size / 2)
    {
      while (node_position > 1 && target_position >= 1)
      {
        node_position--;
        target_position--;
        cost++;
      }
    }
    else if (node_position >= node_list_size / 2 && target_position >= target_list_size / 2)
    {
      while (node_position != node_list_size + 1 && target_position != target_list_size)
      {
        node_position++;
        target_position++;
        cost++;
      }
    }
    // Single rotates
    // Rotate A
    if (node_position < node_list_size / 2)
    {
      while (node_position > 1)
      {
        node_position--;
        cost++;
      }
    }
    else
    {
      while (node_position != node_list_size + 1)
      {
        node_position++;
        cost++;
      }
    }
    // Rotate B
    if (target_position < node_list_size / 2)
    {
      while (target_position >= 1)
      {
        target_position--;
        cost++;
      }
    }
    else
    {
      while(target_position != target_list_size)
      {
        target_position++;
        cost++;
      }
    }
  }
  return (cost);
}
t_list *ft_best_push_pb(t_list **from_list, t_list **to_list)
{
  t_list *curr;
  t_list *best_node;
  int curr_cost;
  int best_cost;

  curr = *from_list;
  best_cost = ft_get_cost_pb(*curr, *ft_get_node(to_list, ft_get_closer_target(curr, to_list)), from_list, to_list);
  best_node = curr;
  while (curr->next)
  {
    curr_cost = ft_get_cost_pb(*curr, *ft_get_node(to_list, ft_get_closer_target(curr, to_list)), from_list, to_list);
    if (curr_cost < best_cost)
    {
      best_cost = curr_cost;
      best_node = curr;
    }
    curr = curr->next;
  }
  curr_cost = ft_get_cost_pb(*curr, *ft_get_node(to_list, ft_get_closer_target(curr, to_list)), from_list, to_list);
    if (curr_cost < best_cost)
    {
      best_cost = curr_cost;
      best_node = curr;
    }
  return (best_node);
}

t_list *ft_best_push_pa(t_list **from_list, t_list **to_list)
{
  t_list *curr;
  t_list *best_node;
  int curr_cost;
  int best_cost;

  curr = *from_list;
  best_cost = ft_get_cost_pa(*curr, *ft_get_node(to_list, ft_get_closer_target(curr, to_list)), from_list, to_list);
  best_node = curr;
  while (curr->next)
  {
    curr_cost = ft_get_cost_pa(*curr, *ft_get_node(to_list, ft_get_closer_target(curr, to_list)), from_list, to_list);
    if (curr_cost < best_cost)
    {
      best_cost = curr_cost;
      best_node = curr;
    }
    curr = curr->next;
  }
  curr_cost = ft_get_cost_pa(*curr, *ft_get_node(to_list, ft_get_closer_target(curr, to_list)), from_list, to_list);
    if (curr_cost < best_cost)
    {
      best_cost = curr_cost;
      best_node = curr;
    }
  return (best_node);
}
