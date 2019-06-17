/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:06:02 by nwispmot          #+#    #+#             */
/*   Updated: 2019/06/17 21:06:05 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_operations(t_pu *pu, char letter)
{
	if (pu->size_a > 1 && letter == 'a')
		ft_swap(&pu->stack_a[0], &pu->stack_a[1]);
	if (pu->size_a > 1 && letter == 'b')
		ft_swap(&pu->stack_b[0], &pu->stack_b[1]);
	if (letter == 's')
	{
		swap_operations(pu, 'a');
		swap_operations(pu, 'b');
	}
}

void	ft_pa(t_pu *pu, int i)
{
	if (pu->size_a > 0)
		while (i > 0)
		{
			pu->stack_a[i] = pu->stack_a[i - 1];
			i--;
		}
	i = -1;
	ft_swap(&pu->stack_b[0], &pu->stack_a[0]);
	pu->size_b--;
	pu->size_a++;
	while (++i < pu->size_b)
		pu->stack_b[i] = pu->stack_b[i + 1];
}

void	push_operations(t_pu *pu, char letter)
{
	int i;

	i = letter == 'a' ? pu->size_a : pu->size_b;
	if (letter == 'b' && pu->size_a > 0)
	{
		if (pu->size_b > 0)
			while (i > 0)
			{
				pu->stack_b[i] = pu->stack_b[i - 1];
				i--;
			}
		i = -1;
		ft_swap(&pu->stack_a[0], &pu->stack_b[0]);
		pu->size_a--;
		pu->size_b++;
		while (++i < pu->size_a)
			pu->stack_a[i] = pu->stack_a[i + 1];
	}
	else if (letter == 'a' && pu->size_b > 0)
		ft_pa(pu, i);
}

void	rotate_operations(t_pu *pu, char letter)
{
	long	tmp;
	int		i;

	i = -1;
	tmp = letter == 'a' ? pu->stack_a[0] : pu->stack_b[0];
	if (letter == 'a' && pu->size_a > 1)
	{
		while (++i < pu->size_a)
			pu->stack_a[i] = pu->stack_a[i + 1];
		pu->stack_a[pu->size_a - 1] = tmp;
	}
	else if (letter == 'b' && pu->size_a > 1)
	{
		while (++i < pu->size_b)
			pu->stack_b[i] = pu->stack_b[i + 1];
		pu->stack_b[pu->size_b - 1] = tmp;
	}
	else if (letter == 'r')
	{
		rotate_operations(pu, 'a');
		rotate_operations(pu, 'b');
	}
	printstack(pu);
}

void	reverse_rotate_operations(t_pu *pu, char letter)
{
	long	tmp;
	int		i;

	i = letter == 'a' ? pu->size_a - 1 : pu->size_b - 1;
	tmp = letter == 'a' ? pu->stack_a[i] : pu->stack_b[i];
	if (letter == 'a' && pu->size_a > 1)
	{
		i++;
		while (--i > 0)
			pu->stack_a[i] = pu->stack_a[i - 1];
		pu->stack_a[0] = tmp;
	}
	else if (letter == 'b' && pu->size_b > 1)
	{
		i++;
		while (--i > 0)
			pu->stack_b[i] = pu->stack_b[i - 1];
		pu->stack_b[0] = tmp;
	}
	else if (letter == 'r')
	{
		reverse_rotate_operations(pu, 'a');
		reverse_rotate_operations(pu, 'b');
	}
}
