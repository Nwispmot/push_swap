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