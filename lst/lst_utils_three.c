/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:01:38 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/16 01:09:26 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_rra(t_list **list_a)
{
	t_list	*tmp;

	tmp = ft_lstlast(*list_a);
	tmp->prev->next = NULL;
	ft_lstadd_front(list_a, tmp);
	*list_a = tmp;
  write(1, "rra\n", 4);
}

void	ft_swap_rrb(t_list **list_b)
{
	t_list	*tmp;

	tmp = ft_lstlast(*list_b);
	tmp->prev->next = NULL;
	ft_lstadd_front(list_b, tmp);
	*list_b = tmp;
  write(1, "rrb\n", 4);
}

void	ft_swap_rrr(t_list **list_a, t_list **list_b)
{
	ft_swap_rra(list_a);
	ft_swap_rrb(list_b);
  write(1, "rrr\n", 4);
}

t_list	*ft_make_list(char **av, int ac)
{
	int		i;
	t_list	*list;

	if (ac > 2)
		i = 1;
	else
		i = 0;
	list = NULL;
	while (av[i])
	{
		ft_lstadd_back(&list, ft_lstnew(ft_atol(av[i])));
		i++;
	}
	return (list);
}

void	ft_free_list(t_list **list)
{
	t_list	*curr;
	t_list	*prev_temp;

	curr = ft_lstlast(*list);
	while (curr->prev != NULL)
	{
		prev_temp = curr->prev;
		free(curr);
		curr = prev_temp;
	}
	free(curr);
	free(list);
}
