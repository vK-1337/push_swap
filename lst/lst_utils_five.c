/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:18:09 by vda-conc          #+#    #+#             */
/*   Updated: 2024/01/01 19:48:41 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_get_node(t_list **list, int position)
{
	t_list	*curr;
	int		i;

	i = 1;
	curr = *list;
	while (i < position)
	{
		curr = curr->next;
		i++;
	}
	return (curr);
}

void	ft_write_instruction_output(char *str)
{
	ft_putstr_fd(str, 1);
}

t_list	*ft_copy_list(t_list *src)
{
	t_list	*head;
	t_list	*current;
	t_list	*new_node;

	head = NULL;
	current = NULL;
	while (src != NULL)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
			return (NULL);
		ft_copy_node(src, new_node);
		if (head == NULL)
		{
			head = new_node;
			current = new_node;
		}
		else
		{
			new_node->prev = current;
			current->next = new_node;
			current = new_node;
		}
		src = src->next;
	}
	return (head);
}

void	ft_copy_node(t_list *src_node, t_list *copy)
{
	if (!src_node || !copy)
		return ;
	copy->content = src_node->content;
	copy->group = src_node->group;
	copy->index = src_node->index;
	copy->position = src_node->position;
	copy->prev = NULL;
	copy->next = NULL;
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
