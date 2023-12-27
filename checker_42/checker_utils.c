/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:49:12 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/27 11:57:16 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_and_apply_instructions(t_list **list_a)
{
	char	*instructions;
	char	**moves;
	int		total_size;

	total_size = ft_lstsize(*list_a);
	instructions = ft_strdup("");
	if (!ft_get_instructions(&instructions, list_a))
	{
		free(instructions);
		return ;
	}
	moves = ft_split(instructions, '\n');
	ft_apply_instructions(list_a, moves);
	free(instructions);
	ft_free_memory(moves);
	if (ft_already_sorted(list_a) && ft_lstsize(*list_a) == total_size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
