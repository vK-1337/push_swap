/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:59:43 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/16 01:10:08 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_node(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = b->next;
	b->next = a;
	a->next = tmp;
}

void	ft_swap_a(t_list **list)
{
	if (*list != NULL && (*list)->next != NULL)
	{
		ft_swap_node(*list, (*list)->next);
	}
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **list)
{
	if (*list != NULL && (*list)->next != NULL)
	{
		ft_swap_node(*list, (*list)->next);
	}
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_list **list_a, t_list **list_b)
{
	ft_swap_a(list_a);
	ft_swap_b(list_b);
  write(1, "ss\n", 3);
}

void	ft_swap_pb(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (*list_a == NULL)
	{
		printf("List A is empty. Cannot perform 'push b'.\n");
		return ;
	}
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = *list_b;
	*list_b = tmp;
  write(1, "pb\n", 3);
}
