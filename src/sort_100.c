/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:37:38 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/19 12:36:36 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function sort an stack of 100 numbers or less.
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @param	int biggest_num		: The biggest alias_num of stack.
 * @return	void
*/
void	ft_sort_100(t_stack **stack_a, t_stack **stack_b, int biggest_num)
{
	int	chunks;
	int	biggest_pos;
	int	smallest_num;

	(void) stack_b;
	smallest_num = 1;
	chunks = biggest_num / 4;
	while (ft_get_stack_size(*stack_a) > 0)
	{
		ft_push_chunk_to_b(stack_a, stack_b, smallest_num);
		smallest_num = smallest_num + chunks;
	}
	while (ft_get_stack_size(*stack_b) > 0)
	{
		biggest_pos = ft_get_biggest_num_pos(stack_b);
		if (biggest_pos <= (ft_get_stack_size(*stack_b) / 2))
			ft_up_num_from_top_pa(stack_a, stack_b, biggest_pos);
		else if (biggest_pos > (ft_get_stack_size(*stack_b) / 2))
			ft_up_num_from_bot_pa(stack_a, stack_b, biggest_pos);
	}
}

/**
 * This function sort an stack of 500 numbers or less.
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @param	int biggest_num		: The biggest alias_num of stack.
 * @return	void
*/
void	ft_sort_500(t_stack **stack_a, t_stack **stack_b, int biggest_num)
{
	int	chunks;
	int	biggest_pos;
	int	smallest_num;

	(void) stack_b;
	smallest_num = 1;
	chunks = biggest_num / 8;
	while (ft_get_stack_size(*stack_a) > 0)
	{
		ft_push_chunk_to_b(stack_a, stack_b, smallest_num);
		smallest_num = smallest_num + chunks;
	}
	while (ft_get_stack_size(*stack_b) > 0)
	{
		biggest_pos = ft_get_biggest_num_pos(stack_b);
		if (biggest_pos <= (ft_get_stack_size(*stack_b) / 2))
			ft_up_num_from_top_pa(stack_a, stack_b, biggest_pos);
		else if (biggest_pos > (ft_get_stack_size(*stack_b) / 2))
			ft_up_num_from_bot_pa(stack_a, stack_b, biggest_pos);
	}
}
