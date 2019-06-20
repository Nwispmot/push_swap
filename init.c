/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:20:34 by nwispmot          #+#    #+#             */
/*   Updated: 2019/06/17 21:20:36 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialization(t_pu *pu)
{
	pu->stack_a = NULL;
	pu->stack_b = NULL;
	pu->size_a = 0;
	pu->i = 0;
	pu->size_b = 0;
	pu->min = 2147483647;
	pu->max = -2147483648;
	pu->option_v = 0;
}

void	printstack(t_pu *pu)
{
	int i;
	int t;

	i = -1;
	t = pu->size_a > pu->size_b ? pu->size_a : pu->size_b;
	if (pu->option_v == 1)
	{
		ft_printf("\n----------------------------\n");
		ft_printf("|%-11c ||" "%11c |\n", 'a', 'b');
		ft_printf("----------------------------");
		ft_printf("\n");
		while (++i < t)
		{
			if (i < pu->size_a)
				ft_printf("|%11ld |", pu->stack_a[i]);
			else
				ft_printf("|%11s |", " ");
			if (i < pu->size_b)
				ft_printf("|%11ld |\n", pu->stack_b[i]);
			else
				ft_printf("|%11s |\n", " ");
		}
		ft_printf("----------------------------\n");
	}
}

void	rotate(t_pu *pu, int i)
{
	while (pu->stack_a[i] != pu->min)
		i++;
	if (i <= pu->size_a / 2)
	{
		while (pu->stack_a[0] != pu->min)
		{
			rotate_operations(pu, 'a');
			ft_printf("ra\n");
		}
	}
	else
		while (pu->stack_a[pu->size_a - 1] != pu->max)
		{
			reverse_rotate_operations(pu, 'a');
			ft_printf("rra\n");
		}
}
