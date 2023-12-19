/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:11:50 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/19 17:35:11 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list **list)
{
	t_list	*curr;
	int		i;

	curr = *list;
	i = 1;
	while (curr->next != NULL)
	{
		// printf("Adresse du node %d |%p|\n",i ,curr);
		printf("Contenu du node %d |%d|\n", i, curr->content);
		// printf("Contenu du node %d ->next |%p|\n", i, curr->next);
		// printf("Contenu de node %d ->prev |%p|\n", i, curr->prev);
		curr = curr->next;
		i++;
	}
	// printf("Adresse du node %d |%p|\n",i ,curr);
	printf("Contenu du node %d |%d|\n", i, curr->content);
	// printf("Contenu du node %d ->next |%p|\n", i, curr->next);
	// printf("Contenu de node %d ->prev |%p|\n", i, curr->prev);
	i++;
}
