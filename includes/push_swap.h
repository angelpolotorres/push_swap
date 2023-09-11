/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:19 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/11 16:29:47 by apolo-to         ###   ########.fr       */
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

void	ft_parse_str_to_num(const char *str, t_stack **stack_a);
int		ft_is_sorted(t_stack *stack);
void	ft_sort_stack(t_stack **stack_a);
void	ft_sort_3(t_stack **stack_a);
void	ft_swap_a(t_stack **stack);
void	ft_rotate_a(t_stack **stack);
void	ft_rev_rotate_a(t_stack **stack);
void	ft_swap_b(t_stack **stack);
void	ft_rotate_b(t_stack **stack);
void	ft_rev_rotate_b(t_stack **stack);
void	ft_free(t_stack *stack);
void	ft_exit(int error_type);
void	ft_free_exit(t_stack *stack, int error_type);
#endif