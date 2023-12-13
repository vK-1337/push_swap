/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:40:32 by vda-conc          #+#    #+#             */
/*   Updated: 2023/12/12 10:03:29 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>


typedef struct s_list
{
	int			nbr;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;            


int	ft_check_args(int ac, char **av);

#endif