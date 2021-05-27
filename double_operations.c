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
