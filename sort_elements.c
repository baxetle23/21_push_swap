#include "./includes/push_swap.h"
void	print_stack(t_stack *stack);
void	print_flags(t_flags *flags);

void	refresh_flags(t_stack *stack_a, t_flags *flags)
{
	t_list	*list;
	int		i;

	i = 1;
	list = stack_a->begin;
	while (list->flag == 1)
	{
		if (flags->max < list->order)
			flags->max = list->order;
		i++;
		list = list->next;
	}
}

void	first_step(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	t_list	*list;

	list = stack_a->begin;
	while (check_stack_min(stack_a, flags))
	{
		if (list->order <= flags->mid)
			push_operation(stack_a, stack_b, stack_b->type);
		else
			rotate_operation(stack_a, stack_a->type);
		list = stack_a->begin;
	}
}

void	second_step(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	t_list	*list;
	int		pos;

	list = stack_b->begin;
	flags->max = flags->mid;
	flags->mid = (flags->max - flags->next) / 2 + flags->next;
	flags->flag++;
	while (check_stack_max(stack_b, flags, &pos))
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
		{
			// printf("CHECK111111\n");
			// print_stack(stack_b);
			// print_flags(flags);
			if (pos == 1)
				rotate_operation(stack_b, stack_b->type);
			else if (pos == -1)
				rrotate_operation(stack_b, stack_b->type);
			// print_stack(stack_b);
			// print_flags(flags);
		}
		list = stack_b->begin;
	}
}

void	sort_iz_a_v_b_flag_1(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	t_list	*list;

	list = stack_a->begin;
	while (list->flag == 1)
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

void	print_stack(t_stack *stack)
{
	t_list *list;

	list = stack->begin;
	printf("PRINT STACK %c\n", stack->type);
	while (list)
	{
		printf("value = %ld  order = %d  flag = %d\n", list->value, list->order, list->flag);
		list = list->next;
	}
}

void	print_flags(t_flags *flags)
{
	printf("PRINT FLFAGS\n");
	printf("max - %d   mid - %d   flag - %d   next - %d\n", flags->max, flags->mid, flags->flag, flags->next);
}

void	sort_elements(t_stack *stack_a, t_stack *stack_b, long *buffer)
{
	t_flags	flags;

	initzilization_flags(&flags, stack_a, buffer);
	if (stack_a->size < 6)
	{
		sort_small_elements_stack_a(stack_a, stack_b);
		return ;
	}
	first_step(stack_a, stack_b, &flags);
	second_step(stack_a, stack_b, &flags);
	sort_iz_a_v_b(stack_a, stack_b, &flags);
	while (stack_b->size > 2)
	{
		sort_iz_b_v_a(stack_a, stack_b, &flags);
		sort_iz_a_v_b(stack_a, stack_b, &flags);
		// print_stack(stack_a);
		// print_stack(stack_b);
		// flags.mid = (flags.max - flags.next) / 2 + flags.next;
		// flags.flag++;
		// print_flags(&flags);
	}
	sort_small_elements(stack_a, stack_b, &flags);
	refresh_flags(stack_a, &flags);
	sort_iz_a_v_b_flag_1(stack_a, stack_b, &flags);
	while (stack_b->size > 2)
	{
		sort_iz_b_v_a(stack_a, stack_b, &flags);
		sort_iz_a_v_b(stack_a, stack_b, &flags);
	}
	sort_small_elements(stack_a, stack_b, &flags);
}
