/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:07:30 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/26 15:24:19 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int main()
{
  char* line;
  char* buffer;
  buffer = malloc(sizeof(char));
  line = malloc(sizeof(char) * 3);
  while(get_next_line(0, &buffer))
    line = ft_strjoin(line, buffer);
}
