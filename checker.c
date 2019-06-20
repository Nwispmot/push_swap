/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:25:51 by nwispmot          #+#    #+#             */
/*   Updated: 2019/06/17 21:25:53 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker(t_pu *pu)
{
	int		i;
	int		pre;

	i = 1;
	if (pu->stack_a[0] != pu->min)
		return (0);
	pre = pu->stack_a[0];
	while (i < pu->size_a)
	{
		if (pu->stack_a[i] < pre)
			return (0);
		pre = pu->stack_a[i];
		i++;
	}
	if (pu->stack_a[pu->size_a - 1] != pu->max)
		return (0);
	return (1);
}

void	doop(t_pu *pu, char **oper, int i)
{
	if (ft_strcmp(oper[i], "ra") == 0)
		rotate_operations(pu, 'a');
	else if (ft_strcmp(oper[i], "rb") == 0)
		rotate_operations(pu, 'b');
	else if (ft_strcmp(oper[i], "rr") == 0)
		rotate_operations(pu, 'r');
	else if (ft_strcmp(oper[i], "rra") == 0)
		reverse_rotate_operations(pu, 'a');
	else if (ft_strcmp(oper[i], "rrb") == 0)
		reverse_rotate_operations(pu, 'b');
	else if (ft_strcmp(oper[i], "rrr") == 0)
		reverse_rotate_operations(pu, 'r');
	else if (ft_strcmp(oper[i], "pa") == 0)
		push_operations(pu, 'a');
	else if (ft_strcmp(oper[i], "pb") == 0)
		push_operations(pu, 'b');
	else if (ft_strcmp(oper[i], "sa") == 0)
		swap_operations(pu, 'a');
	else if (ft_strcmp(oper[i], "sb") == 0)
		swap_operations(pu, 'b');
	else
	{
		ft_printf("Error\n");
		exit(0);
	}
}

void	read_input(t_pu *pu)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*temp;
	char	**oper;
	int		i;

	i = 0;
	temp = ft_strnew(0);
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin_free(temp, buff, 1, 0);
		i++;
	}
	if (i == 0)
		return ;
	oper = ft_strsplit(temp, '\n');
	i = -1;
	while (oper[++i] != NULL)
		doop(pu, oper, i);
}

int		main(int ac, char **av)
{
	int		count;
	t_pu	*pu;

	count = 0;
	pu = (t_pu *)malloc(sizeof(t_pu));
	ft_initialization(pu);
	while (++count < ac)
		ft_valid(av[count], pu);
	if (pu->size_a > 0)
	{
		pu->stack_a = (long *)malloc(pu->size_a * sizeof(long));
		pu->stack_b = (long *)malloc(pu->size_a * sizeof(long));
		count = 0;
		while (++count < ac)
			ft_record(pu, av[count]);
		ft_check_repeat(pu);
		read_input(pu);
		printstack(pu);
		if (checker(pu) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	exit(0);
}
