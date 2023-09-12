/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:35:33 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/12 12:03:09 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * This ft push down the stack A so the last element becomes the first one.
 * Then print "rra" on screen.
 * @param	t_stack** stack_a	: The stack A.
 * @return	void
*/
void	ft_rev_rotate_a(t_stack **stack_a)
{
	t_stack	*top_num;
	t_stack	*semi_bot_num;
	t_stack	*bot_num;

	top_num = *stack_a;
	semi_bot_num = top_num->next;
	while (semi_bot_num->next->next != NULL)
		semi_bot_num = semi_bot_num->next;
	bot_num = semi_bot_num->next;
	bot_num->next = top_num;
	semi_bot_num->next = NULL;
	*stack_a = bot_num;
	ft_printf("rra\n");
}

/**
 * This ft push down the stack B so the last element becomes the first one.
 * Then print "rrb" on screen.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_rev_rotate_b(t_stack **stack_b)
{
	t_stack	*top_num;
	t_stack	*semi_bot_num;
	t_stack	*bot_num;

	top_num = *stack_b;
	semi_bot_num = top_num->next;
	while (semi_bot_num->next->next != NULL)
		semi_bot_num = semi_bot_num->next;
	bot_num = semi_bot_num->next;
	bot_num->next = top_num;
	semi_bot_num->next = NULL;
	*stack_b = bot_num;
	ft_printf("rrb\n");
}

/**
 * This ft push down the stack A so the last element becomes the first one.
 * Then repeat the process with Stack B.
 * Then print "rra" and "rrb" on screen.
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_rev_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate_a(stack_a);
	ft_rev_rotate_b(stack_b);
}
