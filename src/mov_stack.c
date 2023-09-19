/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:31:53 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/19 10:50:23 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function moves a num from top half stack B to the top using rotate
 * Then push the number to stack A using push.
 * @param	t_stack* stack_a	: The A stack.
 * @param	t_stack* stack_b	: The B stack.
 * @param	int pos				: The position of number.
 * @return	void
*/
void	ft_up_num_from_top_pa(t_stack **stack_a, t_stack **stack_b, int pos)
{
	while (pos > 1)
	{
		ft_rotate_b(stack_b);
		pos--;
	}
	ft_push_a(stack_a, stack_b);
}

/**
 * This function moves a num from bottom half stack B to the top using rotate
 * Then push the number to stack A using push.
 * @param	t_stack* stack_a	: The A stack.
 * @param	t_stack* stack_b	: The B stack.
 * @param	int pos				: The position of number.
 * @return	void
*/
void	ft_up_num_from_bot_pa(t_stack **stack_a, t_stack **stack_b, int pos)
{
	while (pos <= ft_get_stack_size(*stack_b))
	{
		ft_rev_rotate_b(stack_b);
		pos++;
	}
	ft_push_a(stack_a, stack_b);
}

/**
 * This function moves a num from top half stack A to the top using rotate
 * Then push the number to stack B using push.
 * @param	t_stack* stack_a	: The A stack.
 * @param	t_stack* stack_b	: The B stack.
 * @param	int pos				: The position of number.
 * @return	void
*/
void	ft_up_num_from_top_pb(t_stack **stack_a, t_stack **stack_b, int pos)
{
	while (pos > 1)
	{
		ft_rotate_a(stack_a);
		pos--;
	}
	ft_push_b(stack_a, stack_b);
}

/**
 * This function moves a num from bottom half stack A to the top using rotate
 * Then push the number to stack B using push.
 * @param	t_stack* stack_a	: The A stack.
 * @param	t_stack* stack_b	: The B stack.
 * @param	int pos				: The position of number.
 * @return	void
*/
void	ft_up_num_from_bot_pb(t_stack **stack_a, t_stack **stack_b, int pos)
{
	while (pos <= ft_get_stack_size(*stack_a))
	{
		ft_rev_rotate_a(stack_a);
		pos++;
	}
	ft_push_b(stack_a, stack_b);
}
