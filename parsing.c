/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:58:13 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/20 17:59:35 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_validity(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_single_arg(char *str)
{
	int		i;
	long	nbr;
	char	**tab;

	if (!ft_check_validity(str))
		return (0);
	tab = ft_split(str, ' ');
	i = 0;
	while (tab[i])
	{
		nbr = ft_atol(tab[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (0);
		i++;
	}
	if (i == 1 || ft_is_same(i, tab))
		return (0);
	return (1);
}

int	ft_check_multiple_args(int ac, char **av)
{
	int		i;
	long	nbr;

	i = 1;
	while (i < ac)
	{
		nbr = ft_atol(av[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (0);
		if (!ft_check_validity(av[i]))
			return (0);
		i++;
	}
	if (ft_is_same(ac, av))
		return (0);
	return (1);
}

int	ft_is_same(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
      {
				return (1);
      }
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parse(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_check_single_arg(av[1]))
			return (0);
	}
	else
	{
		if (!ft_check_multiple_args(ac, av))
			return (0);
	}
	return (1);
}
