#include "./includes/push_swap.h"

void	swap_d_operation(t_stack *stack1, t_stack *stack2)
{
	swap_operation(stack1, 'd');
	swap_operation(stack2, 'd');
	write(1, "ss\n", 3);
}

void	rotate_d_operation(t_stack *stack1, t_stack *stack2)
{
	rotate_operation(stack1, 'd');
	rotate_operation(stack2, 'd');
	write(1, "rr\n", 3);
}

void	rrotate_d_operation(t_stack *stack1, t_stack *stack2)
{
	rotate_operation(stack1, 'd');
	rotate_operation(stack2, 'd');
	write(1, "rrr\n", 4);
}

void	sort_buffer(long *buffer, int size)
{
	int		i;
	int		j;
	long	tmp;

	i = 1;
	while (i < size)
	{
		j = size;
		while (j > i)
		{
			if (buffer[j - 1] > buffer[j])
			{
				tmp = buffer[j - 1];
				buffer[j - 1] = buffer[j];
				buffer[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

void	get_order(t_stack *stack, long *buffer)
{
	t_list	*list;
	int		i;

	list = stack->begin;
	while (list)
	{
		i = 0;
		while (1)
		{
			if (list->value == buffer[i])
			{
				list->order = i + 1;
				break ;
			}
			i++;
		}
		list = list->next;
	}
}
