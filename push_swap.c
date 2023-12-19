/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/19 17:19:19 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_execute_moves_a(t_list **list_a, t_list **list_b, t_target_info positions)
{
  ft_multiple_moves(&positions.pos_to_insert, &positions.target_pos, list_a, list_b);
  ft_move_a(&positions.pos_to_insert, list_a);
  ft_move_b(&positions.target_pos, list_b);
  if ((*list_b)->content < (*list_a)->content)
    ft_swap_rb(list_b, 0);
  ft_swap_pb(list_a, list_b);
}

void ft_execute_moves_b(t_list **list_a, t_list **list_b, t_target_info positions)
{
  ft_multiple_moves(&positions.target_pos, &positions.pos_to_insert, list_a, list_b);
  ft_move_a(&positions.target_pos, list_a);
  ft_move_b(&positions.pos_to_insert, list_b);
  if ((*list_a)->content < (*list_b)->content)
    ft_swap_ra(list_a, 0);
  ft_swap_pa(list_a, list_b);
}
void ft_move_a(int *a_node_pos, t_list **list_a)
{
  int a_size;

  a_size = ft_lstsize(*list_a);
  if (*a_node_pos > a_size / 2)
	{
		while (*a_node_pos <= a_size)
		{
      ft_swap_rra(list_a, 0);
			(*a_node_pos)++;
    }
	}
	else if (*a_node_pos < a_size / 2)
	{
		while (*a_node_pos > 1)
		{
      ft_swap_ra(list_a, 0);
			(*a_node_pos)--;
		}
	}
}

void ft_move_b(int *b_node_pos, t_list **list_b)
{
  int b_size;
  b_size = ft_lstsize(*list_b);
  if (*b_node_pos > b_size / 2)
	{
		while (*b_node_pos <= b_size && *b_node_pos != 1)
		{
      ft_swap_rrb(list_b, 0);
			(*b_node_pos)++;
    }
	}
	else if (*b_node_pos < b_size / 2)
	{
		while (*b_node_pos > 1)
		{
      ft_swap_rb(list_b, 0);
			(*b_node_pos)--;
		}
	}
}

void ft_multiple_moves(int *a_node_pos, int *b_node_pos, t_list **list_a, t_list **list_b)
{
  int a_size;
  int b_size;

  a_size = ft_lstsize(*list_a);
  b_size = ft_lstsize(*list_b);
	if ((*a_node_pos > a_size / 2) && (*b_node_pos > b_size / 2))
	{
		while ((*a_node_pos <= a_size) && (*b_node_pos <= b_size))
		{
      if (*a_node_pos == 1 || *b_node_pos == 1)
        break;
      ft_swap_rrr(list_a, list_b);
			(*a_node_pos)++;
			(*b_node_pos)++;
		}
	}
	else if ((*a_node_pos <= a_size / 2) && (*b_node_pos <= b_size / 2))
	{
		while (*a_node_pos > 1 && *b_node_pos > 1)
		{
      ft_swap_rr(list_a, list_b);
			(*a_node_pos)--;
			(*b_node_pos)--;
		}
	}
}

void	ft_sort(t_list **list_a)
{
	t_list			**list_b;
	t_target_info	positions;

	if (ft_lstsize(*list_a) == 3)
		return (ft_three_sort_a(list_a));
	list_b = malloc(sizeof(t_list *));
  if (ft_lstsize(*list_a) == 4)
    ft_swap_pb(list_a, list_b);
  else
  {
    ft_swap_pb(list_a, list_b);
    ft_swap_pb(list_a, list_b);
  }
	while (ft_lstsize(*list_a) >= 4)
	{
		positions = ft_cheapest_moves_a(list_a, list_b);
		ft_execute_moves_a(list_a, list_b, positions);
	}
	ft_three_sort_a(list_a);
	while (ft_lstsize(*list_b) > 0)
	{
		positions = ft_cheapest_moves_b(list_a, list_b);
		ft_execute_moves_b(list_a, list_b, positions);
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
			target_position = i;
			content_diff = ft_content_diff(a_list_node, curr);
		}
		i++;
		curr = curr->next;
	}
	if ((ft_content_diff(a_list_node, curr)) <= content_diff)
	{
		target_position = i;
		content_diff = ft_content_diff(a_list_node, curr);
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

t_target_info	ft_cheapest_moves_a(t_list **list_a, t_list **list_b)
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

t_target_info	ft_cheapest_moves_b(t_list **list_a, t_list **list_b)
{
	int				i;
	int				cost;
	int				target_position;
	t_list			*curr_b;
	t_target_info	insertion_info;

	curr_b = *list_b;
	i = 1;
	target_position = ft_get_target(curr_b, list_a);
	cost = ft_cost(i, target_position, list_b, list_a);
	insertion_info.target_pos = target_position;
	insertion_info.pos_to_insert = i;
	while (curr_b != NULL)
	{
		target_position = ft_get_target(curr_b, list_a);
		if (ft_cost(i, target_position, list_b, list_a) < cost)
		{
			insertion_info.target_pos = target_position;
			insertion_info.pos_to_insert = i;
			cost = ft_cost(i, target_position, list_b, list_a);
		}
		i++;
		curr_b = curr_b->next;
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
  ft_final_sort(list_a);
  ft_print_list(list_a);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
	ft_push_swap(ac, av);
  ft_write_instruction(NULL);
	return (0);
}
