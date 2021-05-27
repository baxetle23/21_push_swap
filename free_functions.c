#include "./includes/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 1;
	while (split[i])
		free(split[i++]);
	free (split[0]);
	split = NULL;
}

void	free_stack(t_list **lst)
{
	t_list	*pointer;

	while (*lst)
	{
		pointer = *lst;
		*lst = (*lst)->next;
		free(pointer);
	}
	lst = NULL;
}

void	initzilization_flags(t_flags *flags, t_stack *stack_a, long *buffer)
{
	flags->next = 1;
	flags->mid = stack_a->size / 2 + flags->next;
	flags->max = stack_a->size;
	flags->flag = 1;
}

int	initzilization(t_stack *stack1, t_stack *stack2, long **buffer, int argc)
{
	stack1->type = 'a';
	stack2->type = 'b';
	stack1->begin = NULL;
	stack2->begin = NULL;
	stack1->size = argc - 1;
	stack2->size = 0;
	*buffer = (long *)malloc((argc - 1) * sizeof(long));
	if (buffer == NULL)
		return (0);
	return (1);
}
