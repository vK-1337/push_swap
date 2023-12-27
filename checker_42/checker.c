/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:07:30 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/27 13:43:34 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int	ft_allowed_instruction(char *buffer)
{
	if (ft_strlen(buffer) > 4)
		return (0);
	if (ft_check_swap_instructions(buffer))
		return (1);
	else if (ft_check_push_instructions(buffer))
		return (1);
	else if (ft_check_rotate_instructions(buffer))
		return (1);
	else if (ft_check_reverse_rotate_instructions(buffer))
		return (1);
	return (0);
}

int	ft_get_instructions(char **instructions, t_list **list_a)
{
	char	*buffer;

	while (get_next_line(0, &buffer, 0))
	{
		if (!ft_verify_instruction(buffer))
		{
			get_next_line(0, &buffer, 1);
			free(buffer);
			ft_free_list(list_a);
			return (0);
		}
		*instructions = ft_strjoin(*instructions, buffer);
	}
	return (1);
}

void	ft_execute_instruction(char *instruction, t_list **list_a,
		t_list **list_b)
{
	if (ft_strncmp(instruction, "sa", 2) == 0)
		ft_swap_a(list_a, 1);
	else if (ft_strncmp(instruction, "sb", 2) == 0)
		ft_swap_b(list_b, 1);
	else if (ft_strncmp(instruction, "ss", 2) == 0)
		ft_swap_ss(list_a, list_b, 1);
	else if (ft_strncmp(instruction, "pa", 2) == 0)
		ft_swap_pa(list_a, list_b, 1);
	else if (ft_strncmp(instruction, "pb", 2) == 0)
		ft_swap_pb(list_a, list_b, 1);
	else if (ft_strncmp(instruction, "ra", 2) == 0)
		ft_swap_ra(list_a, 0, 1);
	else if (ft_strncmp(instruction, "rb", 2) == 0)
		ft_swap_rb(list_b, 0, 1);
	else if (ft_strncmp(instruction, "rra", 3) == 0)
		ft_swap_rra(list_a, 0, 1);
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		ft_swap_rrb(list_b, 0, 1);
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		ft_swap_rrr(list_a, list_b, 1);
	else if (ft_strncmp(instruction, "rr", 2) == 0)
		ft_swap_rr(list_a, list_b, 1);
}

int	ft_apply_instructions(t_list **list_a, char **instructions)
{
	int		i;
	t_list	*list_b;

	list_b = NULL;
	i = 0;
	while (instructions[i])
	{
		ft_execute_instruction(instructions[i], list_a, &list_b);
		i++;
	}
	ft_free_list(&list_b);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	char	**list;

	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
	if (ac > 2)
		list_a = ft_make_list(ac, av);
	else
	{
		list = ft_split(av[1], ' ');
		list_a = ft_make_list(ac, list);
		ft_free_memory(list);
	}
	if (ft_already_sorted(&list_a))
	{
		ft_free_list(&list_a);
		write(1, "OK\n", 3);
		return (0);
	}
	ft_get_and_apply_instructions(&list_a);
	ft_free_list(&list_a);
	return (0);
}
