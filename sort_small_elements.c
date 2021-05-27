#include "./includes/push_swap.h"

void	sort_small_elements(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	if (stack_b->size == 3)
		sort_size_3(stack_a, stack_b, flags);
	else if (stack_b->size == 2)
		sort_size_2(stack_a, stack_b, flags);
	else if (stack_b->size == 1)
		sort_size_1(stack_a, stack_b, flags);
}

int	find_min_stack_a(t_stack *stack_a)
{
	int		min;
	int		count;
	t_list	*list;

	min = 999;
	list = stack_a->begin;
	while (list)
	{
		if (min > list->order)
			min = list->order;
		list = list->next;
	}
	return (min);
}

void	sort_4_elements_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int		count_min;
	t_list	*list;

	list = stack_a->begin;
	count_min = find_min_stack_a(stack_a);
	while (count_min != list->order)
	{
		rotate_operation(stack_a, stack_a->type);
		list = stack_a->begin;
	}
	push_operation(stack_a, stack_b, stack_b->type);
	sort_3_elements(stack_a);
	push_operation(stack_b, stack_a, stack_a->type);
}

void	sort_5_elements_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int		count_min;
	t_list	*list;

	while (stack_b->size != 2)
	{
		list = stack_a->begin;
		count_min = find_min_stack_a(stack_a);
		while (count_min != list->order)
		{
			rotate_operation(stack_a, stack_a->type);
			list = stack_a->begin;
		}
		push_operation(stack_a, stack_b, stack_b->type);
	}
	sort_3_elements(stack_a);
	push_operation(stack_b, stack_a, stack_a->type);
	push_operation(stack_b, stack_a, stack_a->type);
}

void	sort_small_elements_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		swap_operation(stack_a, stack_a->type);
	else if (stack_a->size == 3)
		sort_3_elements(stack_a);
	else if (stack_a->size == 4)
		sort_4_elements_stack_a(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_5_elements_stack_a(stack_a, stack_b);
}
