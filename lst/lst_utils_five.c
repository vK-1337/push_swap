/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:18:09 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/26 12:46:00 by vda-conc         ###   ########.fr       */
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
