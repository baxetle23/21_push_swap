#include "./includes/push_swap.h"

int	check_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i]) || (i == 0 && (s[i] == '-' || s[i] == '+'))))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int size, long *buffer)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (buffer[i] == buffer[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char *s)
{
	long	number;

	if (ft_strlen(s) > 13)
		return (0);
	number = ft_atoi(s);
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (1);
}

int	check_argument(char *string)
{
	long	number;

	if (!check_digit(string) || !check_int(string))
		return (0);
	return (1);
}

int	check_arg_and_fill_buffer(int argc, char **argv, long *buffer)
{
	int	i;

	i = 0;
	while (argc - ++i > 0)
	{
		if (!check_argument(argv[argc - i]))
		{
			free (buffer);
			return (0);
		}
		buffer[argc - i] = ft_atoi(argv[argc - i]);
	}
	if (!check_duplicates(argc, buffer))
	{
		free (buffer);
		return (0);
	}
	return (1);
}
