/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chosenumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:16:03 by nwispmot          #+#    #+#             */
/*   Updated: 2019/06/20 20:16:05 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace2(t_swap *swap, int j)
{
	if (swap->ra > j)
	{
		swap->ra = 0;
		swap->rra = j;
	}
	while (swap->ra != 0 && swap->rb != 0)
	{
		swap->ra--;
		swap->rb--;
		swap->rr++;
	}
	while (swap->rra != 0 && swap->rrb != 0)
	{
		swap->rra--;
		swap->rrb--;
		swap->rrr++;
	}
}

void	replace(t_pu *pu, t_swap *swap, int j, int num)
{
	int i;

	i = pu->size_a;
	while (--i > 0)
	{
		if (num == pu->min)
		{
			if (pu->stack_a[i - 1] == pu->max)
				break ;
		}
		else
		{
			if (pu->stack_a[i] > num && pu->stack_a[i - 1] < num)
				break ;
		}
		j++;
	}
	replace2(swap, j);
}

int		ft_chosenumber(t_pu *pu, t_swap *swap, int num, int i)
{
	swap->ra = 0;
	swap->rr = 0;
	swap->rra = 0;
	swap->rrr = 0;
	while (++i < pu->size_a)
	{
		if (num == pu->min)
		{
			if (pu->stack_a[i] == pu->max)
				break ;
		}
		else
		{
			if (pu->stack_a[0] > num && pu->stack_a[pu->size_a - 1] < num)
				return (swap->rb + swap->rrb);
			if (pu->stack_a[i] < num && pu->stack_a[i + 1] > num)
				break ;
		}
	}
	swap->ra = ++i;
	replace(pu, swap, 1, num);
	return (swap->ra + swap->rb + swap->rr + swap->rra + swap->rrb +
			swap->rrr);
}
