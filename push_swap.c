/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:26:02 by nwispmot          #+#    #+#             */
/*   Updated: 2019/05/25 15:26:07 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_operations2(t_pu *pu, t_swap *swap)
{
	while (swap->rra-- != 0)
	{
		reverse_rotate_operations(pu, 'a');
		ft_printf("rra\n");
	}
	while (swap->rrb-- != 0)
	{
		reverse_rotate_operations(pu, 'b');
		ft_printf("rrb\n");
	}
	while (swap->rrr-- != 0)
	{
		reverse_rotate_operations(pu, 'r');
		ft_printf("rrr\n");
	}
}

void	do_operations(t_pu *pu, t_swap *swap)
{
	while (swap->ra-- != 0)
	{
		rotate_operations(pu, 'a');
		ft_printf("ra\n");
	}
	while (swap->rb-- != 0)
	{
		rotate_operations(pu, 'b');
		ft_printf("rb\n");
	}
	while (swap->rr-- != 0)
	{
		rotate_operations(pu, 'r');
		ft_printf("rr\n");
	}
	do_operations2(pu, swap);
}

int		checksort(t_pu *pu, int i)
{
	if ((pu->stack_a[0] == pu->min && pu->stack_a[pu->size_a - 1] == pu->max
	&& pu->stack_a[1] > pu->stack_a[0]) || (pu->stack_a[0] == pu->max &&
	pu->stack_a[pu->size_a - 1] < pu->stack_a[0] && pu->stack_a[1] == pu->min)
	|| (pu->stack_a[1] > pu->stack_a[0] && pu->stack_a[pu->size_a - 1]
	< pu->stack_a[0]))
		i++;
	else
		return (0);
	while (i < pu->size_a - 1)
	{
		if ((pu->stack_a[i] == pu->min && pu->stack_a[i - 1] == pu->max &&
		pu->stack_a[i + 1] > pu->stack_a[i]) || (pu->stack_a[i] == pu->max
		&& pu->stack_a[i + 1] == pu->min && pu->stack_a[i - 1] < pu->stack_a[i])
		|| (pu->stack_a[i - 1] < pu->stack_a[i] && pu->stack_a[i + 1] >
		pu->stack_a[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int		sorted(t_pu *pu, int r)
{
	int i;

	if (checksort(pu, 0) == 0)
		return (0);
	if ((pu->stack_a[pu->size_a - 1] == pu->min && pu->stack_a[pu->size_a - 2]
	== pu->max && pu->stack_a[pu->size_a - 1] < pu->stack_a[0]) ||
	(pu->stack_a[pu->size_a - 1] == pu->max && pu->stack_a[pu->size_a - 2] <
	pu->stack_a[pu->size_a - 1] && pu->stack_a[0] == pu->min) ||
	(pu->stack_a[pu->size_a - 1] > pu->stack_a[pu->size_a - 2] &&
	pu->stack_a[pu->size_a - 1] < pu->stack_a[0]))
		i = 0;
	else
		return (0);
	if (r == 1)
		rotate(pu, i);
	exit(0);
}

int		main(int ac, char **av)
{
	int		count;
	t_pu	*pu;
	t_swap	*swap;

	count = 0;
	swap = (t_swap *)malloc(sizeof(t_swap));
	pu = (t_pu *)malloc(sizeof(t_pu));
	ft_initialization(pu);
	while (++count < ac)
		ft_valid(av[count], pu);
	pu->stack_a = (long *)malloc(pu->size_a * sizeof(long));
	pu->stack_b = (long *)malloc(pu->size_a * sizeof(long));
	count = 0;
	while (++count < ac)
		ft_record(pu, av[count]);
	ft_check_repeat(pu);
	if (pu->size_a > 1)
	{
		printstack(pu);
		if (sorted(pu, 1) != 0)
			exit(0);
		ft_sort(pu, swap);
	}
	exit(0);
}
