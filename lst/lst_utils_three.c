/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:01:38 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/30 23:50:42 by vk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_rra(t_list **list_a, int is_rrr, int is_checker, char **instructions)
{
	t_list	*tmp;

	if (!*list_a || ft_lstsize(*list_a) < 2)
		return ;
	tmp = ft_lstlast(*list_a);
	if (!tmp)
		return ;
	if (tmp->prev)
		tmp->prev->next = NULL;
	ft_lstadd_front(list_a, tmp);
	ft_refresh_pos(list_a);
	if (!is_rrr && !is_checker)
  {
    // ft_write_instruction_output("rra\n");
		ft_write_instruction("rra\n", instructions);
  }
}

void	ft_swap_rrb(t_list **list_b, int is_rrr, int is_checker, char **instructions)
{
	t_list	*tmp;

	if (!*list_b || ft_lstsize(*list_b) < 2)
		return ;
	tmp = ft_lstlast(*list_b);
	if (!tmp)
		return ;
	if (tmp->prev)
		tmp->prev->next = NULL;
	ft_lstadd_front(list_b, tmp);
	ft_refresh_pos(list_b);
	if (!is_rrr && !is_checker)
  {
		ft_write_instruction("rrb\n", instructions);
  }
}

void	ft_swap_rrr(t_list **list_a, t_list **list_b, int is_checker, char **instructions)
{
	ft_swap_rra(list_a, 1, is_checker, instructions);
	ft_swap_rrb(list_b, 1, is_checker, instructions);
	ft_refresh_pos(list_a);
	ft_refresh_pos(list_b);
	if (!is_checker)
  {
		ft_write_instruction("rrr\n", instructions);
  }
}

t_list	*ft_make_list(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	*new_node;

	if (ac > 2)
		i = 1;
	else
		i = 0;
	list = NULL;
	while (av[i])
	{
		new_node = ft_lstnew(ft_atol(av[i]));
    if (!new_node)
      return (NULL);
		ft_lstadd_back(&list, new_node);
		i++;
	}
	return (list);
}

void	ft_free_list(t_list **list)
{
	t_list	*tmp;

	if (!list || !*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}
