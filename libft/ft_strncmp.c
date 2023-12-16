/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:28:21 by vk                #+#    #+#             */
/*   Updated: 2023/12/16 16:20:24 by vk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	if ((!first && !second) || length == 0)
		return (0);
	i = 0;
	while (i < length && (first[i] || second[i]))
	{
		if (first[i] != second[i])
			return ((unsigned char)(first[i]) - (unsigned char)(second[i]));
		i++;
	}
	return (0);
}
