/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:19 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/13 15:14:31 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>

enum	e_error
{
	NO_ERROR = 0,
	ERROR = -1,
	E_INVALID_PARAM = 2,
	E_PARAMS_NOT_FOUND = 3,
	E_INT_LIMITS_EXCEEDED = 4,
	E_MALLOC_FAIL = 5,
};

enum	e_sorted
{
	NO_SORTED = 0,
	SORTED = 1,
};

typedef struct s_stack
{
	int				num;
	int				a_num;
	struct s_stack	*next;
}	t_stack;

/* ---- Utils ---- */
void	ft_parse_str_to_num(const char *str, t_stack **stack_a);
int		ft_is_stack_sorted(t_stack *stack);
void	ft_sort_stack(t_stack **stack_a);
int		ft_get_stack_size(t_stack *stack);
int		ft_get_smallest_num_pos(t_stack **stack);
int		ft_get_biggest_num_pos(t_stack **stack);
void	up_num_from_top(t_stack **s_a, t_stack **s_b, int num_pos, char tar);
void	up_num_from_bot(t_stack **s_a, t_stack **s_b, int num_pos, char tar);
void	ft_sort_100(t_stack **stack_a, t_stack **stack_b, int biggest_num);

/* ---- Sort movements ---- */
void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_rev_rotate_a(t_stack **stack_a);
void	ft_rev_rotate_b(t_stack **stack_b);
void	ft_rev_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);

/* ---- Error, free and exit ---- */
void	ft_free(t_stack *stack);
void	ft_exit(int error_type);
void	ft_free_exit(t_stack *stack, int error_type);

/* ---- DELETE ---- */
void	ft_print_stack(t_stack *stack);
#endif