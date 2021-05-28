#include "./includes/push_swap.h"

void	print_error(long *buffer)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	clear_and_exit(long *buffer)
{
	free(buffer);
	print_error(buffer);
}

void	algo(t_stack *stack_a, t_stack *stack_b, long *buffer, int size)
{
	if (!fill_stack(&(stack_a->begin), buffer, size))
		print_error(buffer);
	if (check_sort(buffer, stack_a->size))
	{
		free(buffer);
		free_stack(&(stack_a->begin));
		exit (1);
	}
	sort_buffer(buffer, stack_a->size);
	get_order(stack_a, buffer + 1);
	sort_elements(stack_a, stack_b, buffer + 1);
	free_stack(&(stack_a->begin));
	free(buffer);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**split;
	long	*buf;

	if (argc > 2)
	{
		if (!initzilization(&stack_a, &stack_b, &buf, argc))
			return (0);
		if (!check_arg_and_fill_buffer(argc, argv, buf))
			print_error(buf);
	}
	else if (argc == 2)
	{
		split = initzilization_str(&stack_a, &stack_b, &buf, argv[1]);
		if (split == NULL)
			return (0);
		if (!check_arg_and_fill_buffer_str(buf, split, stack_a.size))
			clear_and_exit(buf);
		argc = stack_a.size + 1;
	}
	else
		return (0);
	algo(&stack_a, &stack_b, buf, argc);
	return (0);
}
