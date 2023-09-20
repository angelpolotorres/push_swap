/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:19 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/20 09:45:32 by apolo-to         ###   ########.fr       */
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

/* ---- Parse ---------- */
void	ft_parse_str_to_num(const char *str, t_stack **stack_a);

/* ---- Sort ----------- */
void	ft_sort_stack(t_stack **stack_a);
void	ft_sort_100(t_stack **stack_a, t_stack **stack_b, int biggest_num);
void	ft_sort_500(t_stack **stack_a, t_stack **stack_b, int biggest_num);

/* ---- Stack Utils ---- */
int		ft_is_stack_sorted(t_stack *stack);
int		ft_get_stack_size(t_stack *stack);
int		ft_get_smallest_num(t_stack **stack);
int		ft_get_smallest_num_pos(t_stack **stack);
int		ft_get_biggest_num(t_stack **stack);
int		ft_get_biggest_num_pos(t_stack **stack);
t_stack	*ft_get_last_stack_node(t_stack *stack);
void	ft_add_node_beginning_stack(t_stack **stack, t_stack *node);
void	ft_add_node_end_stack(t_stack **stack, t_stack *node);
int		ft_nums_under_limit(t_stack **stack_a, int smallest_num);
void	ft_print_stack(t_stack *stack);

/* ---- Stack Movements ---- */
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_push_chunk_to_b(t_stack **stack_a,
			t_stack **stack_b, int smallest_num);
void	ft_up_num_from_top_pa(t_stack **stack_a, t_stack **stack_b, int pos);
void	ft_up_num_from_bot_pa(t_stack **stack_a, t_stack **stack_b, int pos);
void	ft_up_num_from_top_pb(t_stack **stack_a, t_stack **stack_b, int pos);
void	ft_up_num_from_bot_pb(t_stack **stack_a, t_stack **stack_b, int pos);
void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_rev_rotate_a(t_stack **stack_a);
void	ft_rev_rotate_b(t_stack **stack_b);
void	ft_rev_rotate_ab(t_stack **stack_a, t_stack **stack_b);

/* ---- Errors, free and exit ---- */
void	ft_exit(int error_type);
void	ft_free(t_stack *stack);
void	ft_exit_error(int error_type);
void	ft_free_exit_error(t_stack *stack, int error_type);
#endif