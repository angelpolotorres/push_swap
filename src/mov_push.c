/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:27:31 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/19 17:08:56 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * This ft push a nbr from stack A to stack B.
 * Then print "pa" on screen.
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (ft_get_stack_size(*stack_b) > 0)
	{
		aux = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_add_node_beginning_stack(stack_a, aux);
		ft_printf("pa\n");
	}
}

/**
 * This ft push a nbr from stack B to stack A.
 * Then print "pb" on screen.
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (ft_get_stack_size(*stack_a) > 0)
	{
		aux = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_add_node_beginning_stack(stack_b, aux);
		ft_printf("pb\n");
	}
}

/**
 * This ft push a nbr from stack B to stack A.
 * Then print "pb" on screen.
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int num)
{
	int		count;

	count = ft_nums_under_limit(stack_a, num);
	while (count > 0)
	{
		if ((*stack_a)->a_num <= num)
		{
			ft_push_b(stack_a, stack_b);
			count--;
		}
		else
			ft_rotate_a(stack_a);
	}
}
