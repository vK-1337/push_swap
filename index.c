/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:38:45 by vda-conc          #+#    #+#             */
/*   Updated: 2024/01/01 19:45:35 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_next_min(t_list **list, t_list *previous_min_node)
{
	t_list	*curr;
	t_list	*next_min;
	int		first_min;

	first_min = ft_get_first_min(list, previous_min_node);
	curr = *list;
	while (curr)
	{
		if (first_min >= curr->content
			&& curr->content > previous_min_node->content)
		{
			next_min = curr;
			first_min = next_min->content;
		}
		curr = curr->next;
	}
	return (next_min);
}

int	ft_get_first_min(t_list **list, t_list *previous_min_node)
{
	t_list	*curr;
	int		first_min;

	first_min = 0;
	curr = *list;
	while (curr)
	{
		if (curr->content > previous_min_node->content)
		{
			first_min = curr->content;
			break ;
		}
		curr = curr->next;
	}
	return (first_min);
}

void	ft_index_list(t_list **list)
{
	int		min_position;
	t_list	*min_node;
	t_list	*next_min;
	int		lst_size;
	int		i;

	i = 1;
	lst_size = ft_lstsize(*list);
	min_position = ft_find_lst_min_pos(list);
	min_node = ft_get_node(list, min_position);
	min_node->index = i;
	min_node->group = 1;
	while (i != lst_size)
	{
		i++;
		next_min = ft_get_next_min(list, min_node);
		next_min->index = i;
		ft_define_node_group(next_min, list);
		min_node = next_min;
	}
	ft_refresh_pos(list);
}

void	ft_define_node_group(t_list *node, t_list **list)
{
	int	total_size;
	int	group;
	int	divider;

	group = 1;
	total_size = ft_lstsize(*list);
	if (total_size > 200)
		divider = 6;
	else
		divider = 3;
	while (!node->group)
	{
		if (node->index < (total_size * group) / divider || group == divider)
			node->group = group;
		group++;
	}
}
