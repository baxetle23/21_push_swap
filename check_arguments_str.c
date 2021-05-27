#include "./includes/push_swap.h"

int	check_sort(long *buf, size_t size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		if (buf[i] > buf[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	fill_stack(t_list **start, long *buffer, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (size - ++i > 0)
	{
		tmp = ft_lstnew(buffer[size - i]);
		tmp->flag = 1;
		if (tmp == NULL)
		{
			free(buffer);
			free_stack(start);
			return (0);
		}
		ft_lstadd_front(start, tmp);
	}
	return (1);
}

char	**initzilization_str(t_stack *st1, t_stack *st2, long **buf, char *s)
{
	int		argc;
	char	**split;

	argc = 0;
	split = ft_split(s, ' ');
	if (split == NULL)
		return (NULL);
	while (split[argc])
		argc++;
	st1->type = 'a';
	st2->type = 'b';
	st1->begin = NULL;
	st2->begin = NULL;
	st1->size = argc;
	st2->size = 0;
	*buf = (long *)malloc((argc + 1) * sizeof(long));
	if (buf == NULL)
	{
		free_split(split);
		return (NULL);
	}
	return (split);
}

int	check_arg_and_fill_buffer_str(long *buffer, char **split, int size)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!check_argument(split[i]))
		{
			free_split(split);
			return (0);
		}
		buffer[i + 1] = ft_atoi(split[i]);
		i++;
	}
	free_split(split);
	if (!check_duplicates(size, buffer))
		return (0);
	return (1);
}
