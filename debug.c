/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:11:50 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/22 12:55:52 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list **list)
{
	t_list	*curr;
	int		i;

  if (!(*list))
    return;
	curr = *list;
	i = 1;
	while (curr->next != NULL)
	{
		// printf("Adresse du node %d |%p|\n",i ,curr);
		printf("Contenu du node %d  |%d|\n", i, curr->content);
		// printf("Contenu du node %d ->next |%p|\n", i, curr->next);
		// printf("Contenu de node %d ->prev |%p|\n", i, curr->prev);
    printf("Index => |%d|\n", curr->index);
    printf("Position => |%d|\n", curr->position);
		curr = curr->next;
		i++;
	}
	// printf("Adresse du node %d |%p|\n",i ,curr);
	printf("Contenu du node %d |%d|\n", i, curr->content);
	// printf("Contenu du node %d ->next |%p|\n", i, curr->next);
	// printf("Contenu de node %d ->prev |%p|\n", i, curr->prev);
  printf("Index => |%d|\n", curr->index);
  printf("Position => |%d|\n", curr->position);
	i++;
}

void ft_print_node(t_list *node)
{
  printf("Contenu du node =>: %d\n", node->content);
  printf("Index du node => %d\n", node->index);
 	printf("Contenu du node->next |%p|\n", node->next);
}
