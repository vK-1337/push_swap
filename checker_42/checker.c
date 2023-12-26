/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:07:30 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/26 20:30:05 by vda-conc         ###   ########.fr       */
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

int	ft_check_swap_instructions(char *buffer)
{
	if (ft_strncmp(buffer, "sa\n", 3) == 0)
		return (1);
	else if (ft_strncmp(buffer, "sb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(buffer, "ss\n", 3) == 0)
		return (1);
	return (0);
}

int	ft_check_push_instructions(char *buffer)
{
	if (ft_strncmp(buffer, "pa\n", 3) == 0)
		return (1);
	else if (ft_strncmp(buffer, "pb\n", 3) == 0)
		return (1);
	return (0);
}

int	ft_check_rotate_instructions(char *buffer)
{
	if (ft_strncmp(buffer, "ra\n", 3) == 0)
		return (1);
	else if (ft_strncmp(buffer, "rb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(buffer, "rr\n", 3) == 0)
		return (1);
	return (0);
}

int	ft_check_reverse_rotate_instructions(char *buffer)
{
	if (ft_strncmp(buffer, "rra\n", 4) == 0)
		return (1);
	else if (ft_strncmp(buffer, "rrb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(buffer, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

void	ft_verify_instruction(char *buffer)
{
	if (!ft_allowed_instruction(buffer))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	ft_get_instructions(char **instructions)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * 3);
	while (get_next_line(0, &buffer))
	{
		ft_verify_instruction(buffer);
		*instructions = ft_strjoin(*instructions, buffer);
	}
	free(buffer);
	return ;
}

int	main(int ac, char **av)
{
	char	*instructions;
	t_list	*list_a;

	if (ac < 2)
		return (0);
	if (!ft_parse(ac, av))
		return (write(2, "Error\n", 6), 0);
	if (ac > 2)
		list_a = ft_make_list(ac, av);
	else
		list_a = ft_make_list(ac, ft_split(av[1], ' '));
	if (ft_already_sorted(&list_a))
	{
		write(1, "List already sorted\n", 20);
		return (0);
	}
	instructions = malloc(sizeof(char));
	ft_get_instructions(&instructions);
	ft_apply_instructions(&list_a, ft_split(instructions, '\n'));
	if (ft_already_sorted(&list_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
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
	return (0);
}

void	ft_execute_instruction(char *instruction, t_list **list_a,
		t_list **list_b)
{
	if (ft_strncmp(instruction, "sa", 2) == 0)
		ft_swap_a(list_a);
	else if (ft_strncmp(instruction, "sb", 2) == 0)
		ft_swap_b(list_b);
	else if (ft_strncmp(instruction, "ss", 2) == 0)
		ft_swap_ss(list_a, list_b);
	else if (ft_strncmp(instruction, "pa", 2) == 0)
		ft_swap_pa(list_a, list_b);
	else if (ft_strncmp(instruction, "pb", 2) == 0)
		ft_swap_pb(list_a, list_b);
	else if (ft_strncmp(instruction, "ra", 2) == 0)
		ft_swap_ra(list_a, 0);
	else if (ft_strncmp(instruction, "rb", 2) == 0)
		ft_swap_rb(list_b, 0);
	else if (ft_strncmp(instruction, "rra", 3) == 0)
		ft_swap_rra(list_a, 0);
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		ft_swap_rrb(list_b, 0);
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		ft_swap_rrr(list_a, list_b);
	else if (ft_strncmp(instruction, "rr", 2) == 0)
		ft_swap_rr(list_a, list_b);
}
