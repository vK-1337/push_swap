/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:44:22 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/15 22:55:42 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_list	**list_a;
	t_list	*curr;
	t_list	*tmp_prev;
	int		i;

	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
	printf("BG LE SANG");
	list_a = malloc(sizeof(t_list *));
	if (ac > 2)
		*list_a = ft_make_list(av, ac);
	else
		*list_a = ft_make_list(ft_split(av[1], ' '), ac);
	i = 0;
	curr = *list_a;
	printf("Sens normal :\n");
	while (++i && curr->next != NULL)
	{
		printf("Contenu du noeud numero %d : |%d|\n", i, curr->content);
		curr = curr->next;
	}
	printf("Contenu du noeud numero %d : |%d|\n", i, curr->content);
	printf("\nSens inverse :\n");
	while (curr->prev != NULL)
	{
		printf("Contenu du noeud numero %d : |%d|\n", i, curr->content);
		i--;
		tmp_prev = curr->prev;
		free(curr);
		curr = tmp_prev;
	}
	printf("Contenu du noeud numero %d : |%d|\n", i, curr->content);
	free(curr);
	free(list_a);
	return (0);
}
