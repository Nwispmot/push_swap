#include "push_swap.h"

int	checker(t_pu	*pu)
{
	int i;
	int pre;

	i = 1;
	if (pu->stack_a[0] != pu->min)
		return(0);
	pre = pu->stack_a[0];
	while (i < pu->size_a)
	{
		if (pu->stack_a[i] < pre)
			return(0);
		pre = pu->stack_a[i];
		i++;
	}
	if (pu->stack_a[pu->size_a - 1] != pu->max)
		return(0);
	return(1);
}

void	 read_input(t_pu	*pu)
{
	char	buff[BUFF_SIZE + 1];
	char	*del;
	int		ret;
	char	*temp;
	char	**oper;
	int		i = 0;
	int		len;
	char	*str;

	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		del = temp;
		temp = ft_strjoin(temp, buff);
		//free(del);
	}
	oper = ft_strsplit(temp, '\n');
	len = ft_strlen(oper[0]);
	ft_printf("%d\n", len);
	while (oper[i] != NULL)
	{
		if (i == 0)
		{
			str = oper[i];
			ft_printf("%s\n", (str + 35));
		}
		else
		{
			ft_printf("op%d == %s\n", i, oper[i]);
		}
		i++;
	}
	i = 0;
	while (oper[i] != NULL)
	{
		if (i == 0)
		{
			str = oper[i];
			oper[i] = (str + 35);
		}

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
				ft_printf("Error1\n");
				exit(0);
			}

		i++;
	}
}

int main(int ac, char **av)
{
	int		count;
	t_pu	*pu;
	//t_swap  *swap;

	//swap = (t_swap*)malloc(sizeof(t_swap));

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
	//printstack(pu);
	read_input(pu);
	if (checker(pu) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit (0);
}
