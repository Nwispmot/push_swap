/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:26:33 by nwispmot          #+#    #+#             */
/*   Updated: 2019/05/25 16:26:35 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft/libft.h"

typedef struct	s_push
{
	int		i;
	long 	*stack_a;
	long 	*stack_b;
	int		size_a;
	int		size_b;
}				t_pu;

void		printstack(t_pu *pu);
void		swap_operations(t_pu	*pu, char letter);
void		push_operations(t_pu	*pu, char letter);
void		rotate_operations(t_pu	*pu, char letter);
void		reverse_rotate_operations(t_pu	*pu, char letter);

#endif
