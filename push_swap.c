/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/22 09:08:44 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_swap(t_list **list_a)
{
  t_list **list_b;

  list_b = malloc(sizeof (t_list *));
  while (ft_lstsize(*list_a) > 3 && ft_lstsize(*list_b) < 2)
    ft_swap_pb(list_a, list_b);
  while (ft_lstsize(*list_a) > 3)
  {

  }
}

int	main(int ac, char **av)
{
  t_list *list_a;

	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
  list_a = ft_make_list(ac, av);
  if (ft_already_sorted(&list_a))
    return (0);
  else
	  ft_push_swap(&list_a);
	return (0);
}
