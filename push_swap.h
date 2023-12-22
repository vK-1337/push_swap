/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:32 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/22 09:08:54 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_target_info
{
	int			target_pos;
	int			pos_to_insert;
}				t_target_info;

int				ft_is_same(int ac, char **av);
int				ft_parse(int ac, char **av);
int				ft_check_validity(char *str);
int				ft_check_single_arg(char *str);
int				ft_already_sorted(t_list **list);
int				ft_find_lst_max(t_list **list);
int				ft_find_lst_min(t_list **list);
int				ft_check_multiple_args(int ac, char **av);

void			ft_write_instruction(char *str);

t_list			*ft_make_list(int ac, char **av);
void			ft_three_sort_a(t_list **list);
void ft_push_swap(t_list **list_a);


void			ft_swap_node(t_list *a, t_list *b);
void			ft_swap_rr(t_list **list_a, t_list **list_b);
void			ft_swap_pa(t_list **list_a, t_list **list_b);
void			ft_swap_ra(t_list **list_a, int is_rr);
void			ft_swap_rb(t_list **list_b, int is_rr);
void			ft_swap_a(t_list **list);
void			ft_swap_b(t_list **list);
void			ft_swap_ss(t_list **list_a, t_list **list_b);
void			ft_swap_pb(t_list **list_a, t_list **list_b);
void			ft_swap_rra(t_list **list_a, int is_rrr);
void			ft_swap_rrb(t_list **list_b, int is_rrr);
void			ft_swap_rrr(t_list **list_a, t_list **list_b);

void			ft_print_list(t_list **list);
void			ft_free_list(t_list **list);

#endif
