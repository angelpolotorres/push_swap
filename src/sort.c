/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:57:58 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/19 16:44:08 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This ft checks if stack is sorted.
 * @param	t_stack* stack	: Stack to check.
 * @return	int				: (1)Sorted, (0)No sorted.
*/
int	ft_is_stack_sorted(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node != NULL)
	{
		if (node->next != NULL && node->a_num > node->next->a_num)
			return (NO_SORTED);
		node = node->next;
	}
	return (SORTED);
}

/**
 * This ft sorts an stack with 3 numbers.
 * @param	t_stack** stack		: The stack to sort.
 * @return	void.
*/
void	ft_sort_3(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->a_num;
	mid = (*stack)->next->a_num;
	bot = (*stack)->next->next->a_num;
	if (top > mid && mid < bot && bot > top)
		ft_swap_a(stack);
	else if (top > mid && mid > bot && bot < top)
	{
		ft_swap_a(stack);
		ft_rev_rotate_a(stack);
	}
	else if (top > mid && mid < bot && bot < top)
		ft_rotate_a(stack);
	else if (top < mid && mid > bot && bot > top)
	{
		ft_swap_a(stack);
		ft_rotate_a(stack);
	}
	else if (top < mid && mid > bot && bot < top)
	{
		ft_rev_rotate_a(stack);
	}
}

/**
 * This ft sorts an stack with less than 10 nums.
 * @param	t_stack** stack_a		: The A stack.
 * @param	t_stack** stack_b		: The B stack.
 * @return	void.
*/
void	ft_sort_10(t_stack **stack_a, t_stack **stack_b)
{
	int	num_pos;

	while (ft_get_stack_size(*stack_a) > 3)
	{
		num_pos = ft_get_smallest_num_pos(stack_a);
		if (num_pos <= (ft_get_stack_size(*stack_a) / 2))
			ft_up_num_from_top_pb(stack_a, stack_b, num_pos);
		else
			ft_up_num_from_bot_pb(stack_a, stack_b, num_pos);
	}
	if (ft_is_stack_sorted(*stack_a) == NO_SORTED)
		ft_sort_3(stack_a);
	while (ft_get_stack_size(*stack_b) != 0)
		ft_push_a(stack_a, stack_b);
}

/**
 * This ft sorts an stack choosing the best sort algorithm.
 * @param	t_stack** stack_a		: The A stack to sort.
 * @return	void.
*/
void	ft_sort_stack(t_stack **stack_a)
{
	int		stack_a_size;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a_size = ft_get_stack_size(*stack_a);
	if (stack_a_size == 2)
		ft_swap_a(stack_a);
	if (stack_a_size == 3)
		ft_sort_3(stack_a);
	if (stack_a_size > 3 && stack_a_size <= 10)
		ft_sort_10(stack_a, &stack_b);
	if (stack_a_size > 10 && stack_a_size <= 100)
		ft_sort_100(stack_a, &stack_b, stack_a_size);
	if (stack_a_size > 100 && stack_a_size <= 500)
		ft_sort_500(stack_a, &stack_b, stack_a_size);
}
