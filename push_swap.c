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

void	ft_initialization(t_pu *pu)
{
	pu->stack_a = NULL;
	pu->stack_b = NULL;
	pu->size_a = 0;
	pu->i = 0;
	pu->size_b = 0;
	pu->min = 2147483647;
	pu->max = -2147483648;
	pu->operations = 0; //удалить
	pu->chose[move_a] = 0;
	pu->chose[move_b] = 0;
	pu->chose[res] = 0;
	pu->chose[dir_a] = -1;
	pu->chose[dir_b] = -1;
}

void	printstack(t_pu *pu)
{
	int i;
	int t = pu->size_a > pu->size_b ? pu->size_a : pu->size_b;

	i = -1;
	ft_printf("----------------------------\n");
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
	ft_printf("----------------------------\n\n");
	pu->operations++;
}

int ft_chosenumber(t_pu	*pu, t_swap	*swap, int num)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 1;
	swap->ra = 0;
	swap->rr = 0;
	swap->rra = 0;
	swap->rrr = 0;
	while (i < pu->size_a)
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
				break;
		}
		i++;

	}
	i++;
	swap->ra = i;
	i = pu->size_a - 1;
	while (i > 0)
	{
		if (num == pu->min)
		{
			if (pu->stack_a[i - 1] == pu->max)
				break ;
		}
		else
		{
			if (pu->stack_a[i] > num && pu->stack_a[i - 1] < num)
				break;
		}
		j++;
		i--;
	}
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
	res = swap->ra + swap->rb + swap->rr + swap->rra + swap->rrb + + swap->rrr;
	return(res);
}

void	do_operations(t_pu	*pu, t_swap	*swap)
{
	while(swap->ra-- != 0)
	{
		rotate_operations(pu, 'a');
		//swap->ra--;
		ft_printf("ra\n");
	}
	while(swap->rb-- != 0)
	{
		rotate_operations(pu, 'b');
		//swap->rb--;
		ft_printf("rb\n");
	}
	while(swap->rr-- != 0)
	{
		rotate_operations(pu, 'r');
		//swap->rr--;
		ft_printf("rr\n");
	}
	while(swap->rra-- != 0)
	{
		reverse_rotate_operations(pu, 'a');
		//swap->rra--;
		ft_printf("rra\n");
	}
	while(swap->rrb-- != 0)
	{
		reverse_rotate_operations(pu, 'b');
		//swap->rrb--;
		ft_printf("rra\n");
	}
	while(swap->rrr-- != 0)
	{
		reverse_rotate_operations(pu, 'r');
		//swap->rrr--;
		ft_printf("rrr\n");
	}
}

void ft_push(t_pu	*pu)
{
	int begin;
	int i = 0;
	long pre;

	begin = pu->stack_a[i];
	pre = pu->stack_a[i];
	rotate_operations(pu, 'a');
	ft_printf("ra\n");
	while (pu->stack_a[0] != pu->max)
	{
		if (pu->stack_a[0] > pre)
		{
			pre = pu->stack_a[0];
			rotate_operations(pu, 'a');
			ft_printf("ra\n");
		}
		else {
			push_operations(pu, 'b');
			ft_printf("pb\n");
		}

	}
	rotate_operations(pu, 'a');
	ft_printf("ra\n");
	pre = -2147483649;
	while (pu->stack_a[0] != begin)
	{
		if (pu->stack_a[0] < begin && pu->stack_a[0] > pre)
		{
			pre = pu->stack_a[0];
			rotate_operations(pu, 'a');
			ft_printf("ra\n");
		}
		else {
			push_operations(pu, 'b');
			ft_printf("pb\n");
		}
	}
}

void ft_sort(t_pu	*pu)
{
	int i;
	int res;
	int num;
	t_swap	*swap;

	swap = (t_swap*)malloc(sizeof(t_swap));
	i = 0;
//	while(pu->size_a != 3)
//	{
//		if ((pu->stack_a[0] == pu->max || pu->stack_a[0] == pu->min) && (pu->stack_b[0] < pu->stack_b[1]))
//			rotate_operations(pu, 'r');
//		else if (pu->stack_a[0] == pu->max || pu->stack_a[0] == pu->min)
//			rotate_operations(pu, 'a');
//		else
//		{
//			push_operations(pu, 'b');
//			if (pu->stack_b[0] < pu->stack_b[1] && pu->stack_b[0] > pu->stack_b[2])
//				swap_operations(pu, 'b');
//		}
//	}
//	if (pu->stack_a[1] < pu->stack_a[0] && pu->stack_a[1] > pu->stack_a[2])
//		swap_operations(pu, 'a');
//	else if (pu->stack_a[1] < pu->stack_a[0] && pu->stack_a[1] < pu->stack_a[2])
//		swap_operations(pu, 'a');
//	else if (pu->stack_a[1] > pu->stack_a[0] && pu->stack_a[1] > pu->stack_a[2] && pu->stack_a[0] < pu->stack_a[2])
//		swap_operations(pu, 'a');
	ft_push(pu);
	while (pu->size_b > 0)
	{
		swap->rb = 0;
		swap->rrb = 0;
		res = ft_chosenumber(pu, swap, pu->stack_b[i]);
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
			if (ft_chosenumber(pu, swap, pu->stack_b[i]) < res)
			{
				num = i;
				res = ft_chosenumber(pu, swap, pu->stack_b[i]);
			}
		}
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
		ft_chosenumber(pu, swap, pu->stack_b[num]);
		do_operations(pu, swap);
		push_operations(pu, 'a');
		ft_printf("pa\n");
		i = 0;
	}
	while (pu->stack_a[i] != pu->min)
		i++;
	if	(i <= pu->size_a / 2)
	{
		while (pu->stack_a[0] != pu->min) {
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

int		main(int ac, char **av)
{
	int		count;
	t_pu	*pu;

	count = 0;
	pu = (t_pu*)malloc(sizeof(t_pu));
	ft_initialization(pu);
	while (++count < ac)
		ft_valid(av[count], pu);
	pu->stack_a = (long *)malloc(pu->size_a * sizeof(long));
	pu->stack_b = (long *)malloc(pu->size_a * sizeof(long));
	count = 0;
	while (++count < ac)
		ft_record(pu, av[count]);
	ft_check_repeat(pu);
	printstack(pu);
	ft_sort(pu);
	ft_printf("operations === %d\n", pu->operations);
	exit (0);
}