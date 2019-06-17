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
		ft_printf("ra\n");
	}
	while(swap->rb-- != 0)
	{
		rotate_operations(pu, 'b');
		ft_printf("rb\n");
	}
	while(swap->rr-- != 0)
	{
		rotate_operations(pu, 'r');
		ft_printf("rr\n");
	}
	while(swap->rra-- != 0)
	{
		reverse_rotate_operations(pu, 'a');
		ft_printf("rra\n");
	}
	while(swap->rrb-- != 0)
	{
		reverse_rotate_operations(pu, 'b');
		ft_printf("rrb\n");
	}
	while(swap->rrr-- != 0)
	{
		reverse_rotate_operations(pu, 'r');
		ft_printf("rrr\n");
	}
}

int sorted(t_pu	*pu, int r) {
    int i;

    i = 0;
    if ((pu->stack_a[0] == pu->min && pu->stack_a[pu->size_a - 1] == pu->max && pu->stack_a[1] > pu->stack_a[0]) ||
        (pu->stack_a[0] == pu->max && pu->stack_a[pu->size_a - 1] < pu->stack_a[0] && pu->stack_a[1] == pu->min)
        || (pu->stack_a[1] > pu->stack_a[0] && pu->stack_a[pu->size_a - 1] < pu->stack_a[0]))
        i++;
    else
        return (0);
    while (i < pu->size_a - 1) {
        if (pu->stack_a[i] == pu->min && pu->stack_a[i - 1] == pu->max && pu->stack_a[i + 1] > pu->stack_a[i])
            i++;
        else if (pu->stack_a[i] == pu->max && pu->stack_a[i + 1] == pu->min && pu->stack_a[i - 1] < pu->stack_a[i])
            i++;
        else if (pu->stack_a[i - 1] < pu->stack_a[i] && pu->stack_a[i + 1] > pu->stack_a[i])
            i++;
        else
            return (0);
    }
    if ((pu->stack_a[pu->size_a - 1] == pu->min && pu->stack_a[pu->size_a - 2] == pu->max &&
         pu->stack_a[pu->size_a - 1] < pu->stack_a[0]) ||
        (pu->stack_a[pu->size_a - 1] == pu->max && pu->stack_a[pu->size_a - 2] < pu->stack_a[pu->size_a - 1] &&
         pu->stack_a[0] == pu->min)
        || (pu->stack_a[pu->size_a - 1] > pu->stack_a[pu->size_a - 2] && pu->stack_a[pu->size_a - 1] < pu->stack_a[0]))
        i = 0;
    else
        return (0);
    if (r == 1)
    {
        while (pu->stack_a[i] != pu->min)
            i++;
        if (i <= pu->size_a / 2) {
            while (pu->stack_a[0] != pu->min) {
                rotate_operations(pu, 'a');
                ft_printf("ra\n");
            }
        }
        else
            while (pu->stack_a[pu->size_a - 1] != pu->max) {
                reverse_rotate_operations(pu, 'a');
                ft_printf("rra\n");
            }
    }
	exit (0);
}

void ft_push(t_pu	*pu)
{
		while(pu->size_a > 3)
		{
			if ((pu->stack_a[0] == pu->max || pu->stack_a[0] == pu->min) && (pu->stack_b[0] < pu->stack_b[1]))
			{
				rotate_operations(pu, 'r');
				ft_printf("rr\n");
			} else if (pu->stack_a[0] == pu->max || pu->stack_a[0] == pu->min)
			{
				rotate_operations(pu, 'a');
				ft_printf("ra\n");
			}
			else
				{
				push_operations(pu, 'b');
				ft_printf("pb\n");
				if (pu->stack_b[0] < pu->stack_b[1] && pu->stack_b[0] > pu->stack_b[2])
				{
					swap_operations(pu, 'b');
					ft_printf("sb\n");
				}
			}
		}
		if (pu->stack_a[1] < pu->stack_a[0] && pu->stack_a[1] > pu->stack_a[2])
		{
			swap_operations(pu, 'a');
			ft_printf("sa\n");
		}
		else if (pu->stack_a[1] < pu->stack_a[0] && pu->stack_a[1] < pu->stack_a[2])
		{
			swap_operations(pu, 'a');
			ft_printf("sa\n");
		}
		else if (pu->stack_a[1] > pu->stack_a[0] && pu->stack_a[1] > pu->stack_a[2] && pu->stack_a[0] < pu->stack_a[2])
		{
			swap_operations(pu, 'a');
			ft_printf("sa\n");
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
	if (sorted(pu, 0) == 0)
	{
		ft_printf("Error\n\n");
		exit(0);
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
	if (pu->size_a > 1)
	{
        pu->stack_a = (long *) malloc(pu->size_a * sizeof(long));
        pu->stack_b = (long *) malloc(pu->size_a * sizeof(long));
        count = 0;
        while (++count < ac)
            ft_record(pu, av[count]);
        ft_check_repeat(pu);
        printstack(pu);
        if (sorted(pu, 1) != 0)
            exit(0);
        ft_sort(pu);
    }
	exit (0);
}
