/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:48:49 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/19 17:31:59 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_pa(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	tmp = *list_b;
	*list_b = (*list_b)->next;
	ft_lstadd_front(list_a, tmp);
	ft_write_instruction("pa\n");
}

void	ft_swap_ra(t_list **list_a, int is_rr)
{
	t_list	*tmp;

	tmp = (*list_a)->next;
	ft_lstadd_back(list_a, (*list_a));
	*list_a = tmp;
	if (!is_rr)
		ft_write_instruction("ra\n");
}

void	ft_swap_rb(t_list **list_b, int is_rr)
{
	t_list	*tmp;

	tmp = (*list_b)->next;
	ft_lstadd_back(list_b, (*list_b));
	*list_b = tmp;
	if (!is_rr)
		ft_write_instruction("rb\n");
}

void	ft_swap_rr(t_list **list_a, t_list **list_b)
{
	ft_swap_ra(list_a, 1);
	ft_swap_rb(list_b, 1);
	ft_write_instruction("rr\n");
}
