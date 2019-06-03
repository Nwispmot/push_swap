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
}

void	printstack(t_pu *pu)
{
//	int i;
//	int t = pu->size_a > pu->size_b ? pu->size_a : pu->size_b;
//
//	i = -1;
//	ft_printf("----------------------------\n");
//	ft_printf("|%-11c ||" "%11c |\n", 'a', 'b');
//	ft_printf("----------------------------");
//	ft_printf("\n");
//	while (++i < t)
//	{
//		if (i < pu->size_a)
//			ft_printf("|%11ld |", pu->stack_a[i]);
//		else
//			ft_printf("|%11s |", " ");
//		if (i < pu->size_b)
//			ft_printf("|%11ld |\n", pu->stack_b[i]);
//		else
//			ft_printf("|%11s |\n", " ");
//	}
//	ft_printf("----------------------------\n\n");
	pu->operations++;
}

void	ft_record(t_pu	*pu, char *av)
{
	while(*av != '\0')
	{
		if((*av >= '0'&& *av <= '9') || (*av == '-'))
		{
			pu->stack_a[pu->i] = ft_atol(av);
			if (pu->stack_a[pu->i] < pu->min)
				pu->min = pu->stack_a[pu->i];
			if (pu->stack_a[pu->i] > pu->max)
				pu->max = pu->stack_a[pu->i];
			if (pu->stack_a[pu->i] > 2147483647 || pu->stack_a[pu->i] < -2147483648)
			{
				ft_printf("ERROR");
				exit(0);
			}
			while (*av != ' ' && *av != '\0')
				av++;
			av--;
			pu->i++;
		}
		av++;
	}
}

void ft_sort(t_pu	*pu)
{
	while(pu->size_a != 3)
	{
		if (pu->stack_a[0] == pu->max || pu->stack_a[0] == pu->min)
			rotate_operations(pu, 'a');
		else
			push_operations(pu, 'b');
	}
	if (pu->stack_a[2] != pu->max)
	{
		if (pu->stack_a[0] == pu->max)
			rotate_operations(pu, 'a');
		else
			reverse_rotate_operations(pu, 'a');
	}
	if (pu->stack_a[0] != pu->min)
		swap_operations(pu, 'a');
	while (pu->size_b > 0)
	{
		if(pu->stack_b[0] < pu->stack_a[(pu->size_a / 2) - 1])
		{
			push_operations(pu, 'a');
			rotate_operations(pu, 'a');
			while (pu->stack_a[0] < pu->stack_a[pu->size_a - 1])
				push_operations(pu, 'b');
			reverse_rotate_operations(pu, 'a');
			while (pu->stack_a[0] != pu->min)
				push_operations(pu, 'a');
		}
		else
		{
			while(pu->stack_a[pu->size_a - 1] > pu->stack_b[0])
				reverse_rotate_operations(pu, 'a');
			push_operations(pu, 'a');
			while (pu->stack_a[pu->size_a - 1] != pu->max)
				rotate_operations(pu, 'a');
		}
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