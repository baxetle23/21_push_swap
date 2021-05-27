#include "./includes/push_swap.h"

int	case_3_elements(long first, long second, long third)
{
	if (first > second && second < third && third > first)
		return ('s' + 'a');
	if (first > second && second < third && third < first)
		return ('r' + 'a');
	if (first < second && second > third && third < first)
		return ('r' + 'r' + 'a');
	if (first > second && second > third && third < first)
		return ('s' + 'a' + 'r' + 'r' + 'a');
	if (first < second && second > third && third > first)
		return ('s' + 'a' + 'r' + 'a');
	return (0);
}

void	print_algo(int num, t_stack *stack)
{
	if (num == 's' + 'a')
		swap_operation(stack, stack->type);
	else if (num == 'r' + 'a')
		rotate_operation(stack, stack->type);
	else if (num == 'r' + 'r' + 'a')
		rrotate_operation(stack, stack->type);
	else if (num == 's' + 'a' + 'r' + 'r' + 'a')
	{
		swap_operation(stack, stack->type);
		rrotate_operation(stack, stack->type);
	}
	else if (num == 's' + 'a' + 'r' + 'a')
	{
		swap_operation(stack, stack->type);
		rotate_operation(stack, stack->type);
	}
}

void	sort_3_elements(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = stack->begin;
	second = first->next;
	third = second->next;
	print_algo(case_3_elements(first->value, second->value,
			third->value), stack);
}

void	sort_size_1(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	push_operation(stack_b, stack_a, stack_a->type);
	rotate_operation(stack_a, stack_a->type);
	flags->next++;
}

void	sort_size_3(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	sort_3_elements(stack_b);
	push_operation(stack_b, stack_a, stack_a->type);
	rotate_operation(stack_a, stack_a->type);
	push_operation(stack_b, stack_a, stack_a->type);
	rotate_operation(stack_a, stack_a->type);
	push_operation(stack_b, stack_a, stack_a->type);
	rotate_operation(stack_a, stack_a->type);
	flags->next += 3;
}
