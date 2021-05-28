#include "./includes/push_swap.h"

int	check_stack_max_revers(t_stack *stack, t_flags *flags, int *pos)
{
	t_list	*list;
	int		pos_reverse;
	int		i;

	i = 1;
	list = stack->begin;
	while (list)
	{
		if (list->order >= flags->mid || list->order == flags->next)
			pos_reverse = i;
		i++;
		list = list->next;
	}
	if (stack->size - pos_reverse < *pos)
		*pos = -1;
	else
		*pos = 1;
	return (1);
}

int	check_stack_max(t_stack *stack, t_flags *flags, int *pos)
{
	t_list	*list;

	*pos = 1;
	list = stack->begin;
	while (list)
	{
		if (list->order >= flags->mid || list->order == flags->next)
			return (check_stack_max_revers(stack, flags, pos));
		list = list->next;
		(*pos)++;
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
