/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:08:01 by vda-conc          #+#    #+#             */
/*   Updated: 2024/01/02 10:08:48 by vda-conc         ###   ########.fr       */
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

void	process_iteration(t_list_container *lists, char **best_instructions,
		int *best_instructions_score, int iteration)
{
	char	*curr_iter_instruc;

	if (!lists->list_a)
		return ;
	curr_iter_instruc = ft_push_swap(lists, iteration);
	if (*best_instructions_score > ft_count_instructions(curr_iter_instruc))
	{
		free(*best_instructions);
		*best_instructions = curr_iter_instruc;
		*best_instructions_score = ft_count_instructions(curr_iter_instruc);
	}
	else
		free(curr_iter_instruc);
	ft_free_list(&lists->list_a);
}

char	*ft_brute_force(t_list *list_a, int iteration)
{
	t_list_container	lists;
	char				*best_instructions;
	int					best_instructions_score;
	int					limit;

	if (ft_lstsize(list_a) <= 100)
		limit = ft_lstsize(list_a);
	else if (ft_lstsize(list_a) <= 200)
		limit = 100;
	else
		limit = 40;
	lists.list_a = ft_copy_list(list_a);
	if (!lists.list_a)
		return (NULL);
	lists.list_b = NULL;
	best_instructions = ft_push_swap(&lists, iteration);
	best_instructions_score = ft_count_instructions(best_instructions);
	ft_free_list(&lists.list_a);
	while (++iteration < limit)
	{
		lists.list_a = ft_copy_list(list_a);
		process_iteration(&lists, &best_instructions, &best_instructions_score,
			iteration);
	}
	return (best_instructions);
}
