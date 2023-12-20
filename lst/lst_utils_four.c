/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:48:09 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/20 17:41:33 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_lst_max(t_list **list)
{
	int		i;
	int		max;
	int		max_position;
	t_list	*curr;

	i = 1;
	max_position = 1;
	curr = *list;
	max = curr->content;
	while (curr->next != NULL)
	{
		if (curr->content > max)
		{
			max_position = i;
			max = curr->content;
		}
		curr = curr->next;
		i++;
	}
	if (curr->content > max)
		max_position = i + 1;
	return (max_position);
}

int	ft_find_lst_min(t_list **list)
{
	int		i;
	int		min;
	int		min_position;
	t_list	*curr;

	i = 1;
	min_position = 1;
	curr = *list;
	min = curr->content;
	while (curr->next != NULL)
	{
		if (curr->content < min)
		{
			min_position = i;
			min = curr->content;
		}
		curr = curr->next;
		i++;
	}
	if (curr->content < min)
		min_position = i;
	return (min_position);
}
