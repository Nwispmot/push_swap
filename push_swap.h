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

typedef enum	e_flag
{
	move_a = 0,
	move_b = 1,
	dir_a = 2,
	dir_b = 3,
	res = 4,
}				t_flag;

typedef struct	s_swap
{
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}				t_swap;

typedef struct	s_push
{
	int		i;
	long 	*stack_a;
	long 	*stack_b;
	int		size_a;
	int		size_b;
	int 	max;
	int 	min;
	int 	chose[5];
	int 	res;

	int		operations; //удалить
}				t_pu;

void		printstack(t_pu *pu);
void		swap_operations(t_pu	*pu, char letter);
void		push_operations(t_pu	*pu, char letter);
void		rotate_operations(t_pu	*pu, char letter);
void		reverse_rotate_operations(t_pu	*pu, char letter);
void		ft_count_digits(char *av, t_pu *pu);
void		ft_check_repeat(t_pu	*push);
void		ft_valid(char *av, t_pu *push);

#endif
