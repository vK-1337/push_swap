/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:48:09 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/30 10:45:21 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_node_content(t_list **list, int position)
{
	int		i;
	t_list	*curr;

	i = 2;
	curr = *list;
	while (i <= position && curr->next != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (curr->content);
}

int	ft_find_lst_max_pos(t_list **list)
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
		max_position = i;
	return (max_position);
}

int	ft_find_lst_min_pos(t_list **list)
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
void ft_write_instruction(char *str, char **instructions) {
    if (!instructions) {
        return;
    }
    if (*instructions == NULL) {
        *instructions = ft_strdup(str);
    } else {
        char *temp = ft_strjoin(*instructions, str);
        *instructions = temp;
    }
}
