#include "push_swap.h"

void	swap_operations(t_pu	*pu, char letter) //Операции SA SB SS
{
	if (pu->size_a > 1 && letter == 'a')
		ft_swap(&pu->stack_a[0], &pu->stack_a[1]);
	if(pu->size_a > 1 && letter == 'b')
		ft_swap(&pu->stack_b[0], &pu->stack_b[1]);
	if(letter == 's')
	{
		swap_operations(pu, 'a');
		swap_operations(pu, 'b');
	}
	printstack(pu);
}

void	push_operations(t_pu	*pu, char letter) //Операции PA PB SS
{
	int i;

	i = letter == 'a' ? pu->size_a : pu->size_b;
	if(letter == 'b' && pu->size_a > 0)
	{
		if (pu->size_b > 0)
			while(i > 0)
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
	else if(letter == 'a' && pu->size_b > 0)
	{
		if (pu->size_a > 0)
			while(i > 0)
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
	printstack(pu);
}

void	rotate_operations(t_pu	*pu, char letter) //Операции RA RB RR
{
	long tmp;
	int i;

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

void	reverse_rotate_operations(t_pu	*pu, char letter) //Операции RRA RRB RRR
{
	long tmp;
	int i;

	i = letter == 'a' ? pu->size_a - 1 : pu->size_b - 1;
	tmp = letter == 'a' ? pu->stack_a[i] : pu->stack_b[i];
	if (letter == 'a' && pu->size_a > 1)
	{
		while (i > 0)
		{
			pu->stack_a[i] = pu->stack_a[i - 1];
			i--;
		}
		pu->stack_a[0] = tmp;
	}
	else if (letter == 'b' && pu->size_b > 1)
	{
		while (i > 0)
		{
			pu->stack_b[i] = pu->stack_b[i - 1];
			i--;
		}
		pu->stack_b[0] = tmp;
	}
	else if (letter == 'r')
	{
		reverse_rotate_operations(pu, 'a');
		reverse_rotate_operations(pu, 'b');
	}
	printstack(pu);
}