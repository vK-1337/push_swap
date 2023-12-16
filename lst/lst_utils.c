/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:48:49 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/16 01:10:43 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_pa(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (*list_b == NULL)
	{
		printf("List B is empty. Cannot perform 'push a'.\n");
		return ;
	}
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = *list_a;
	*list_a = tmp;
	write(1, "pa\n", 3);
}

void	ft_swap_ra(t_list **list_a)
{
	t_list	*tmp;

	tmp = (*list_a)->next;
	ft_lstadd_back(list_a, (*list_a));
	(*list_a)->next = NULL;
	*list_a = tmp;
  write(1, "ra\n", 3);
}

void	ft_swap_rb(t_list **list_b)
{
	t_list	*tmp;

	tmp = (*list_b)->next;
	ft_lstadd_back(list_b, (*list_b));
	(*list_b)->next = NULL;
	*list_b = tmp;
  write(1, "rb\n", 3);
}

void	ft_swap_rr(t_list **list_a, t_list **list_b)
{
	ft_swap_ra(list_a);
	ft_swap_rb(list_b);
  write(1, "rr\n", 3);
}
