/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:32:16 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/26 20:32:49 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
