/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:08:01 by vda-conc          #+#    #+#             */
/*   Updated: 2024/01/01 19:52:21 by vda-conc         ###   ########.fr       */
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
	char	*curr_iter_instruc;
	char	*best_instructions;
	int		best_instructions_score;
	t_list	*list_copy;

	list_copy = ft_copy_list(list_a);
	if (!list_copy)
		return (NULL);
	best_instructions = ft_push_swap(&list_copy, iteration);
	best_instructions_score = ft_count_instructions(best_instructions);
	ft_free_list(&list_copy);
	while (++iteration < 40)
	{
		list_copy = ft_copy_list(list_a);
		if (!list_copy)
			return (NULL);
		curr_iter_instruc = ft_push_swap(&list_copy, iteration);
		if (best_instructions_score > ft_count_instructions(curr_iter_instruc))
		{
			free(best_instructions);
			best_instructions = curr_iter_instruc;
			best_instructions_score = ft_count_instructions(curr_iter_instruc);
		}
		else
			free(curr_iter_instruc);
		ft_free_list(&list_copy);
	}
	return (best_instructions);
}
