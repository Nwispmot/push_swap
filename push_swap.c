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
}

void	ft_count_digits(char *av, t_pu *pu)
{
	int i;
	int fl;

	i = 0;
	fl = 0;
	while (av[i] != '\0')
	{
		if (av[i] == ' ')
		{
			i++;
			fl = 0;
		}
		else if (((av[i] >= '0' && av[i] <= '9') || av[i] == '-') && fl == 0)
		{
			pu->size_a++;
			fl = 1;
			i++;
		}
		else if ((av[i] >= '0' && av[i] <= '9') && fl == 1)
			i++;
	}
}

void		ft_check_repeat(t_pu	*push)
{
	int	i;
	int j;

	i = 0;
	while (i < push->size_a)
	{
		j = 0;
		while (j < push->size_a)
		{
			if (i == j || push->stack_a[i] != push->stack_a[j])
				j++;
			else
			{
				ft_printf("Repeating numbers");
				exit(0);
			}
		}
		i++;
	}
}

void		ft_valid(char *av, t_pu *push)
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if ((av[i] == '-' && (av[i + 1] >= '0' && av[i + 1] <= '9')) && (i == 0 || av[i - 1] == ' '))
			i++;
		else if ((av[i] >= '0'&& av[i] <= '9') || (av[i] == ' '))
			i++;
		else
		{
			ft_printf("invalid file\n");
			exit(0);
		}
	}
	ft_count_digits(av, push);
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
}

void	ft_record(t_pu	*pu, char *av)
{
	while(*av != '\0')
	{
		if((*av >= '0'&& *av <= '9') || (*av == '-'))
		{
			pu->stack_a[pu->i] = ft_atol(av);
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
	push_operations(pu, 'b');
	push_operations(pu, 'b');
	push_operations(pu, 'b');
	push_operations(pu, 'b');
	reverse_rotate_operations(pu, 'r');
	reverse_rotate_operations(pu, 'r');
	reverse_rotate_operations(pu, 'r');
	reverse_rotate_operations(pu, 'r');
	exit (0);
}