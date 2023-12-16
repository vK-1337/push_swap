/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:48:09 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/16 00:24:44 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_lst_max(t_list **list)
{
	int		max;
	int		i;
	int		max_position;
	t_list	*curr;

	i = 1;
	curr = *list;
	max = curr->content;
	max_position = 1;
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
