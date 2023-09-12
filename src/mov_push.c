/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:27:31 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/12 11:33:41 by apolo-to         ###   ########.fr       */
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
	t_stack	*top_a;
	t_stack	*top_b;

	if (*stack_b == NULL)
		return ;
	top_b = *stack_b;
	if (top_b->next == NULL)
		*stack_b = NULL;
	else
		*stack_b = top_b->next;
	if (*stack_a == NULL)
	{
		*stack_a = top_b;
		top_b->next = NULL;
	}
	else
	{
		top_a = *stack_a;
		*stack_a = top_b;
		top_b->next = top_a;
	}
	ft_printf("pa\n");
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
	t_stack	*top_a;
	t_stack	*top_b;

	if (*stack_a == NULL)
		return ;
	top_a = *stack_a;
	if (top_a->next == NULL)
		*stack_a = NULL;
	else
		*stack_a = top_a->next;
	if (*stack_b == NULL)
	{
		*stack_b = top_a;
		top_a->next = NULL;
	}
	else
	{
		top_b = *stack_b;
		*stack_b = top_a;
		top_a->next = top_b;
	}
	ft_printf("pb\n");
}
