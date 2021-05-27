#include "./includes/push_swap.h"

void	swap_operation(t_stack *stack, char s)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = stack->begin;
	second = first->next;
	third = second->next;
	first->next = third;
	stack->begin = second;
	second->next = first;
	if (s != 'd')
	{
		write(1, "s", 1);
		write(1, &s, 1);
		write(1, "\n", 1);
	}
}

void	rotate_operation(t_stack *stack, char s)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->begin;
	second = first->next;
	last = ft_lstlast(stack->begin);
	last->next = first;
	first->next = NULL;
	stack->begin = second;
	if (s != 'd')
	{
		write(1, "r", 1);
		write(1, &s, 1);
		write(1, "\n", 1);
	}
}

void	rrotate_operation(t_stack *stack, char s)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->begin;
	second = first->next;
	last = ft_lstlast(stack->begin);
	stack->begin = last;
	last->next = first;
	while (first->next != last)
		first = first->next;
	first->next = NULL;
	if (s != 'd')
	{
		write(1, "rr", 2);
		write(1, &s, 1);
		write(1, "\n", 1);
	}
}

void	push_operation(t_stack *stack_src, t_stack *stack_dst, char s)
{
	t_list	*first_dst;
	t_list	*first_src;

	first_dst = stack_dst->begin;
	first_src = stack_src->begin;
	stack_dst->begin = first_src;
	stack_src->begin = first_src->next;
	first_src->next = first_dst;
	stack_src->size--;
	stack_dst->size++;
	write(1, "p", 1);
	write(1, &s, 1);
	write(1, "\n", 1);
}
