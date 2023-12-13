/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:48:49 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/13 08:46:58 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_node(t_list *a, t_list *b)
{
	t_list *tmp;

	tmp = b->next;
	b->next = a;
	a->next = tmp;
}

void ft_swap_a(t_list **list)
{
    if (*list != NULL && (*list)->next != NULL) {
        ft_swap_node(*list, (*list)->next);
    }
    write(1, "sa", 2);
}

void ft_swap_a(t_list **list)
{
    if (*list != NULL && (*list)->next != NULL) {
        ft_swap_node(*list, (*list)->next);
    }
    write(1, "sa\n", 3);
}

void ft_swap_b(t_list **list)
{
    if (*list != NULL && (*list)->next != NULL) {
        ft_swap_node(*list, (*list)->next);
    }
    write(1, "sb\n", 3);
}
void ft_swap_ss(t_list **list_a, t_list **list_b)
{
  ft_swap_a(list_a);
  ft_swap_b(list_b);
}

void ft_swap_pa(t_list **list_a, t_list **list_b)
{
  t_list *tmp;
  if (*list_b == NULL)
  {
    printf("List B is empty. Cannot perform 'push a'.\n");
    return;
  }
  tmp = *list_a;
  list_a = (*list_a)->next;
  tmp->next = *list_b;
  *list_b = tmp;
  return;
}

void ft_swap_pb(t_list **list_a, t_list **list_b)
{
  t_list *tmp;
    if (*list_a == NULL)
    {
      printf("List A is empty. Cannot perform 'push b'.\n");
      return;
    }
    tmp = *list_b;
    list_b = (*list_b)->next;
    tmp->next = *list_a;
    *list_a = tmp;
    return;
}

void ft_swap_ra(t_list **list_a)
{
// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
}

void ft_swap_rb(t_list **list_b)
{
// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.
}
void ft_swap_rr(t_list **list_a, t_list **list_b)
{
// rr : ra et rb en même temps.
}

void ft_swap_rra(t_list **list_a)
{
// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
}

void ft_swap_rrb(t_list **list_b)
{
// rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.
}

void ft_swap_rrr(t_list **list_a, t_list **list_b)
{
// rrr : rra et rrb en même temps
}

int main()
{
	t_list *list;
	t_list first;
	t_list second;
	t_list third;
	int i;

	first.nbr = 10;
	second.nbr = 20;
	third.nbr = 30;
	first.next = &second;
	second.next = &third;
	third.next = NULL;
	list = &first;


	i = 1;
    while (i <= 3)
    {
        printf("Contenu du noeud numero %d : |%d|\n", i , list->nbr);
        i++;
        list = list->next;
    }

    list = &first;
    ft_swap_a(&list);
    list = &second;

    printf("Apres ft_swap_a : \n");
    i = 1;
    while (i <= 3 && list != NULL)
    {
        printf("Contenu du noeud numero %d : |%d|\n", i , list->nbr);
        i++;
        list = list->next;
    }

    return (0);
}
