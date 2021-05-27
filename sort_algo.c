#include "./includes/push_swap.h"

void	sort_iz_a_v_b(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	t_list	*list;

	list = stack_a->begin;
	while (list->flag == flags->flag)
	{
		if (list->order == flags->next)
		{
			rotate_operation(stack_a, stack_a->type);
			flags->next++;
		}
		else
			push_operation(stack_a, stack_b, stack_b->type);
		list = stack_a->begin;
	}
}

void	sort_iz_b_v_a(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	t_list	*list;

	list = stack_b->begin;
	flags->mid = (flags->max - flags->next) / 2 + flags->next;
	flags->flag++;
	while (check_stack_max(stack_b, flags))
	{
		if (list->order >= flags->mid || list->order == flags->next)
		{
			list->flag = flags->flag;
			push_operation(stack_b, stack_a, stack_a->type);
			if (list->order == flags->next)
			{
				rotate_operation(stack_a, stack_a->type);
				flags->next++;
			}
		}
		else
			rotate_operation(stack_b, stack_b->type);
		list = stack_b->begin;
	}
}

void	sort_size_2(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	if (stack_b->begin->order != flags->next)
		swap_operation(stack_b, stack_b->type);
	push_operation(stack_b, stack_a, stack_a->type);
	rotate_operation(stack_a, stack_a->type);
	push_operation(stack_b, stack_a, stack_a->type);
	rotate_operation(stack_a, stack_a->type);
	flags->next += 2;
}
