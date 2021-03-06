/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:42:48 by nwispmot          #+#    #+#             */
/*   Updated: 2019/06/19 20:42:51 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_push(t_pu *pu, int num)
{
	if (num == 1)
	{
		if (pu->stack_a[1] < pu->stack_a[0] && pu->stack_a[1] > pu->stack_a[2])
		{
			swap_operations(pu, 'a');
			ft_printf("sa\n");
		}
		else if (pu->stack_a[1] < pu->stack_a[0] && pu->stack_a[1] <
		pu->stack_a[2])
		{
			swap_operations(pu, 'a');
			ft_printf("sa\n");
		}
		else if (pu->stack_a[1] > pu->stack_a[0] && pu->stack_a[1] >
		pu->stack_a[2] && pu->stack_a[0] < pu->stack_a[2])
		{
			swap_operations(pu, 'a');
			ft_printf("sa\n");
		}
	}
	else
	{
		rotate_operations(pu, 'r');
		ft_printf("rr\n");
	}
}

void	ft_push(t_pu *pu)
{
	while (pu->size_a > 3)
	{
		if ((pu->stack_a[0] == pu->max || pu->stack_a[0] == pu->min) &&
		(pu->stack_b[0] < pu->stack_b[1]))
			check_push(pu, 0);
		else if (pu->stack_a[0] == pu->max || pu->stack_a[0] == pu->min)
		{
			rotate_operations(pu, 'a');
			ft_printf("ra\n");
		}
		else
		{
			push_operations(pu, 'b');
			ft_printf("pb\n");
			if (pu->stack_b[0] < pu->stack_b[1] && pu->stack_b[0] >
			pu->stack_b[2])
			{
				swap_operations(pu, 'b');
				ft_printf("sb\n");
			}
		}
	}
	check_push(pu, 1);
}

int		sub1(t_pu *pu, t_swap *swap, int i, int num)
{
	int res;

	swap->rb = 0;
	swap->rrb = 0;
	res = ft_chosenumber(pu, swap, pu->stack_b[i], -1);
	num = i;
	while (++i < pu->size_b)
	{
		if (i <= (pu->size_b / 2))
		{
			swap->rb = i;
			swap->rrb = 0;
		}
		else
		{
			swap->rrb = pu->size_b - i;
			swap->rb = 0;
		}
		if (ft_chosenumber(pu, swap, pu->stack_b[i], -1) < res)
		{
			num = i;
			res = ft_chosenumber(pu, swap, pu->stack_b[i], -1);
		}
	}
	return (num);
}

void	sub(t_pu *pu, t_swap *swap)
{
	int num;

	while (pu->size_b > 0)
	{
		num = sub1(pu, swap, 0, 0);
		if (num <= (pu->size_b / 2))
		{
			swap->rb = num;
			swap->rrb = 0;
		}
		else
		{
			swap->rrb = pu->size_b - num;
			swap->rb = 0;
		}
		ft_chosenumber(pu, swap, pu->stack_b[num], -1);
		do_operations(pu, swap);
		push_operations(pu, 'a');
		ft_printf("pa\n");
	}
}

void	ft_sort(t_pu *pu, t_swap *swap)
{
	int	i;

	i = 0;
	ft_push(pu);
	sub(pu, swap);
	while (pu->stack_a[i] != pu->min)
		i++;
	if (i <= pu->size_a / 2)
		while (pu->stack_a[0] != pu->min)
		{
			rotate_operations(pu, 'a');
			ft_printf("ra\n");
		}
	else
		while (pu->stack_a[pu->size_a - 1] != pu->max)
		{
			reverse_rotate_operations(pu, 'a');
			ft_printf("rra\n");
		}
	if (sorted(pu, 0) == 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
}
