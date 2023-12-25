/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:59:43 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/25 16:47:23 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_node(t_list *a, t_list *b)
{
	t_list	*tmp_next;

	tmp_next = b->next;
	tmp_next->prev = a;
	b->next = a;
	b->prev = NULL;
	a->next = tmp_next;
	a->prev = b;
}

void	ft_swap_a(t_list **list)
{
	if (*list != NULL && (*list)->next != NULL)
		ft_swap_node(*list, (*list)->next);
	*list = (*list)->prev;
	ft_refresh_pos(list);
	ft_write_instruction("sa\n");
}

void	ft_swap_b(t_list **list)
{
	if (*list != NULL && (*list)->next != NULL)
		ft_swap_node(*list, (*list)->next);
	*list = (*list)->prev;
	ft_refresh_pos(list);
	ft_write_instruction("sb\n");
}

void	ft_swap_ss(t_list **list_a, t_list **list_b)
{
	ft_swap_a(list_a);
	ft_swap_b(list_b);
	ft_refresh_pos(list_a);
	ft_refresh_pos(list_b);
	ft_write_instruction("ss\n");
}

void	ft_swap_pb(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	tmp = *list_a;
	*list_a = (*list_a)->next;
	ft_lstadd_front(list_b, tmp);
	ft_refresh_pos(list_a);
	ft_refresh_pos(list_b);
	ft_write_instruction("pb\n");
}
