/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:29 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/09 19:06:56 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_args(int ac, char **av)
{
	ssize_t i;
	
	if (ac != 2)
		return	(-1);
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == ' ')
			i++;
		if (av[1][i] == '\0')
			return (0);
		if (av[1][i] < '0' || av[1][i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	if (!ft_check_args(ac, av))
		printf("Propre");
	else
		printf("Belek les args");
	return (0);
}