/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:08:01 by vda-conc          #+#    #+#             */
/*   Updated: 2024/01/01 22:46:33 by vk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_instructions(char *instructions)
{
	char	**final_tab;
	int		i;

	final_tab = ft_split(instructions, '\n');
	if (!final_tab)
		return (-1);
	i = 0;
	while (final_tab[i])
		i++;
	ft_free_memory(final_tab);
	return (i);
}

char	*ft_brute_force(t_list *list_a, int iteration)
{
	t_list_container	lists;
	char				*curr_iter_instruc;
	char				*best_instructions;
	int					best_instructions_score;

	lists.list_a = ft_copy_list(list_a);
	if (!lists.list_a)
		return (NULL);
	lists.list_b = NULL;
	best_instructions = ft_push_swap(&lists, iteration);
	best_instructions_score = ft_count_instructions(best_instructions);
	ft_free_list(&lists.list_a);
	while (++iteration < 40)
	{
		lists.list_a = ft_copy_list(list_a);
		if (!lists.list_a)
			return (NULL);
		curr_iter_instruc = ft_push_swap(&lists, iteration);
		if (best_instructions_score > ft_count_instructions(curr_iter_instruc))
		{
			free(best_instructions);
			best_instructions = curr_iter_instruc;
			best_instructions_score = ft_count_instructions(curr_iter_instruc);
		}
		else
			free(curr_iter_instruc);
		ft_free_list(&lists.list_a);
	}
	return (best_instructions);
}
