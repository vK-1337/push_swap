/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/31 16:51:56 by vk               ###   ########.fr       */
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

void	ft_final_sort(t_list **list_a, char **instructions)
{
	t_list	*min_node;

	min_node = ft_get_node(list_a, ft_find_lst_min_pos(list_a));
	if (min_node->position < ft_lstsize(*list_a) / 2)
	{
		while (min_node->position > 1)
		{
			ft_swap_ra(list_a, 0, 0, instructions);
		}
	}
	else
	{
		while (min_node->position != 1)
		{
			ft_swap_rra(list_a, 0, 0, instructions);
		}
	}
}

void	ft_push_to_b(t_list **list_a, t_list **list_b, int total_size,
		int groups, char **instructions)
{
	while (ft_lstsize(*list_b) < 2 && ft_lstsize(*list_a) > 3)
	{
		if ((*list_a)->group == 1)
			ft_swap_pb(list_a, list_b, 0, instructions);
		else if ((*list_a)->group == 2)
		{
			ft_swap_pb(list_a, list_b, 0, instructions);
			if (ft_lowest_group(list_b) == 1)
				ft_swap_rb(list_b, 0, 0, instructions);
		}
		else
				ft_swap_ra(list_a, 0, 0, instructions);
	}
  if (total_size)
    while ((ft_lstsize(*list_a)) > 3)
      ft_pb_by_three_groups(list_a, list_b, groups, total_size, instructions);
  // else
  //   while ((ft_lstsize((*list_a)) > 3))
  //     ft_pb_by_six_groups(list_a, list_b, groups, total_size, instructions);
}


// void ft_pb_by_six_groups(t_list **list_a, t_list **list_b, int groups,
// 		int total_size, char **instructions)
// {
//   while (ft_lowest_group(list_a) == 1)
//     ft_pb_by_three_groups(list_a, list_b, groups, total_size, instructions);
//   while (ft_lowest_group(list_a) == 2)

// }



void ft_push_by_group(t_list **list_a, t_list **list_b, char **instructions)
{
  int lowest_group;

  lowest_group = ft_lowest_group(list_a);
  if (lowest_group == ft_highest_group(list_a))
    ft_swap_pb(list_a, list_b, 0, instructions);
  else if ((*list_a)->group == lowest_group || (*list_a)->group == lowest_group + 1)
  {
    ft_swap_pb(list_a, list_b, 0, instructions);
    if ((*list_b)->group == lowest_group + 1 && (*list_a)->group == lowest_group + 2)
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
void	ft_pb_by_three_groups(t_list **list_a, t_list **list_b, int groups,
		int total_size, char **instructions)
{
  // Mettre total size et groups dans une struct
	static int	multiplier = 1;

  if (multiplier > ft_highest_group(list_a))
  {
    multiplier = 1;
  }
	while (ft_lstsize(*list_b) <= (total_size * multiplier) / groups && ft_lstsize(*list_a) > 3 && multiplier < 7)
	{
		ft_push_by_group(list_a, list_b, instructions);
	}
	multiplier++;
}

void	ft_push_to_a(t_list *node, t_list *target_node, t_list **list_a,
		t_list **list_b, char **instructions)
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
		ft_multiple_moves_node_lesser(&node, &target_node, list_a, list_b, instructions);
		ft_single_move_node_lesser(&node, &target_node, list_a, list_b, instructions);
	}
	else
	{
		ft_multiple_moves_node_greater(&node, &target_node, list_a, list_b, instructions);
		ft_single_move_node_greater(&node, &target_node, list_a, list_b, instructions);
	}
	ft_swap_pa(list_a, list_b, 0, instructions);
}

char *ft_push_swap(t_list **list_a, int iteration)
{
	t_list	*list_b;
	t_list	*node_to_push;
	t_list	*target_node;
	int		group;
	int		total_size;
  char *instructions = NULL;
  int i;

	total_size = ft_lstsize(*list_a);
	group = ft_highest_group(list_a);
	list_b = NULL;
  i = 0;
  while (i++ < iteration)
    ft_swap_ra(list_a, 0, 0, &instructions);
	ft_push_to_b(list_a, &list_b, total_size, group, &instructions);
	ft_three_sort_a(list_a, &instructions);
	while (ft_lstsize(list_b) > 0)
	{
		node_to_push = ft_best_push_pa(&list_b, list_a, group);
		target_node = ft_get_node(list_a, ft_define_target_pos_pa(node_to_push,
					list_a));
		ft_push_to_a(node_to_push, target_node, list_a, &list_b, &instructions);
		group = ft_highest_group(&list_b);
	}
	ft_final_sort(list_a, &instructions);
  ft_free_list(&list_b);
  return(instructions);
}

char *ft_brute_force(t_list *list_a)
{
  int iteration;
  char *best_instructions;
  t_list *list_copy;
  int best_instructions_score;
  char *curr_iteration_instructions;
  int curr_iteration_score;

  iteration = 0;
  list_copy = ft_copy_list(list_a);
  if (!list_copy)
    return (NULL);
  best_instructions = ft_push_swap(&list_copy, iteration);
  best_instructions_score = ft_count_instructions(best_instructions);
  while (++iteration < 40)
  {
    list_copy = ft_copy_list(list_a);
    curr_iteration_instructions = ft_push_swap(&list_copy, iteration);
    curr_iteration_score = ft_count_instructions(curr_iteration_instructions);
    if (best_instructions_score > ft_count_instructions(curr_iteration_instructions))
    {
      best_instructions = curr_iteration_instructions;
      best_instructions_score = curr_iteration_score;
    }
    ft_free_list(&list_copy);
  }
  return (best_instructions);
}

t_list *ft_copy_list(t_list *src)
{
    t_list *head;
    t_list *current;

    head = NULL;
    current = NULL;
    while (src != NULL) {
        t_list *new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node)
          return (NULL);
        ft_copy_node(src, new_node);
        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
        src = src->next;
    }
    return (head);
}

void ft_copy_node(t_list *src_node, t_list *copy)
{
  if (!src_node || !copy)
    return;
  copy->content = src_node->content;
  copy->group = src_node->group;
  copy->index = src_node->index;
  copy->position = src_node->position;
  copy->prev = src_node->prev;
  copy->next = NULL;
}

int ft_count_instructions(char *instructions)
{
  char **final_tab;
  int i;

  final_tab = ft_split(instructions, '\n');
  if (!final_tab)
    return (-1);
  i = 0;
  while (final_tab[i])
    i++;
  return (i);
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
  char *best_instructions;

	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
	if (ac > 2)
  {
		list_a = ft_make_list(ac, av);
    if (!list_a)
      exit (0);
  }
	else
	{
		list = ft_split(av[1], ' ');
    if(!list)
      exit(0);
		list_a = ft_make_list(ac, list);
    if (!list_a)
      exit (0);
		ft_free_memory(list);
	}
	if (ft_already_sorted(&list_a))
		return (ft_free_list(&list_a), 0);
	else
	{
		ft_index_list(&list_a);
		best_instructions = ft_brute_force(list_a);
    if (best_instructions == NULL)
      return (ft_free_list(&list_a), 0);
	}
  printf("%s", best_instructions);
	return (ft_free_list(&list_a), 0);
}
