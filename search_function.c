#include "./includes/push_swap.h"

int	check_stack_max(t_stack *stack, t_flags *flags)
{
	t_list	*list;

	list = stack->begin;
	while (list)
	{
		if (list->order >= flags->mid || list->order == flags->next)
			return (1);
		list = list->next;
	}
	return (0);
}

int	check_stack_min(t_stack *stack_a, t_flags *flags)
{
	t_list	*list;

	list = stack_a->begin;
	while (list)
	{
		if (list->order <= flags->mid)
			return (1);
		list = list->next;
	}
	return (0);
}

int	check_stack_min_v2(t_stack *stack, t_flags *flags)
{
	t_list	*list;

	list = stack->begin;
	while (list)
	{
		if (list->order <= flags->mid)
			return (1);
		list = list->next;
	}
	return (0);
}
