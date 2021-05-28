#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	t_list	*begin;
	size_t	size;
	char	type;
}	t_stack;

typedef struct s_flags
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}	t_flags;

void	swap_operation(t_stack *stack, char s);
void	rotate_operation(t_stack *stack, char s);
void	rrotate_operation(t_stack *stack, char s);
void	push_operation(t_stack *stack_src, t_stack *stack_dst, char s);

int		check_digit(char *s);
int		check_duplicates(int size, long *buffer);
int		check_sort(long *buf, size_t size);
int		check_int(char *s);
int		check_argument(char *string);
int		check_arg_and_fill_buffer(int argc, char **argv, long *buffer);
int		fill_stack(t_list **start, long *buffer, int size);
int		check_arg_and_fill_buffer_str(long *buffer, char **split, int size);

char	**initzilization_str(t_stack *st1, t_stack *st2, long **buf, char *s);
void	initzilization_flags(t_flags *flags, t_stack *stack_a, long *buffer);
int		initzilization(t_stack *stack1, t_stack *stack2, long **b, int argc);

void	get_order(t_stack *stack, long *buffer);
void	sort_buffer(long *buffer, int size);
void	refresh_flags(t_stack *stack_a, t_flags *flags);

void	free_stack(t_list **lst);
void	free_split(char **split);

int		check_stack_max(t_stack *stack, t_flags *flags, int *pos);
int		check_stack_min(t_stack *stack_a, t_flags *flags);
int		check_stack_min_v2(t_stack *stack, t_flags *flags);

void	sort_small_elements_stack_a(t_stack *stack_a, t_stack *stack_b);
int		case_3_elements(long first, long second, long third);
void	print_algo(int num, t_stack *stack);
void	sort_3_elements(t_stack *stack);
void	sort_size_1(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	sort_size_3(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	sort_size_2(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	sort_small_elements(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	sort_iz_a_v_b(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	sort_iz_b_v_a(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	first_step(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	second_step(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	sort_iz_a_v_b_flag_1(t_stack *stack_a, t_stack *stack_b, t_flags *flag);
void	sort_elements(t_stack *stack_a, t_stack *stack_b, long *buffer);

#endif