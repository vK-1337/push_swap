/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:01:38 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/18 20:17:22 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_swap_rra(t_list **list_a) {
    t_list *tmp;

    tmp = ft_lstlast(*list_a);
    if (tmp && tmp->prev) {
        tmp->prev->next = NULL;
        ft_lstadd_front(list_a, tmp);
	      ft_write_instruction("rra\n");
    }
}

void	ft_swap_rrb(t_list **list_b)
{
	t_list	*tmp;

	tmp = ft_lstlast(*list_b);
  if(tmp->prev)
	  tmp->prev->next = NULL;
	ft_lstadd_front(list_b, tmp);
	ft_write_instruction("rrb\n");
}

void	ft_swap_rrr(t_list **list_a, t_list **list_b)
{
	ft_swap_rra(list_a);
	ft_swap_rrb(list_b);
	ft_write_instruction("rrr\n");
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
