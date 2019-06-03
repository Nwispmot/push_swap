/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:57:35 by nwispmot          #+#    #+#             */
/*   Updated: 2019/06/03 17:57:42 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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