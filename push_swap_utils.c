/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:59:51 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/22 20:11:13 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_define_target_pos(t_list *node, t_list **list)
{
  int target_position;
  t_list *max_node;
  t_list *min_node;

  max_node = ft_get_node(list, ft_find_lst_max_pos(list));
  min_node = ft_get_node(list, ft_find_lst_min_pos(list));
  if (node->content > max_node->content || node->content < min_node->content)
    target_position = max_node->position;
  else
    target_position = ft_get_closer_target(node, list);
  return (target_position);
}

int ft_get_closer_target(t_list *node_to_insert, t_list **list)
{
  t_list *potential_target;
  int target_position;
  int min_diff;
  int diff;

  potential_target = *list;
  min_diff = node_to_insert->index - potential_target->index;
  target_position = potential_target->position;
  while (potential_target->next)
  {
    diff = node_to_insert->index - potential_target->index;
    if (diff < 0)
      diff *= -1;
    if (diff < min_diff)
    {
      target_position = potential_target->position;
      min_diff = diff;
    }
    potential_target = potential_target->next;
  }
  return(target_position);
}

void ft_refresh_pos(t_list **list)
{
  t_list *curr;
  int position;

  curr = *list;
  position = 1;
  curr->position = position;
  while (curr->next)
  {
    position++;
    curr = curr->next;
    curr->position = position;
  }
  curr->position = position;
  return ;
}