/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:27:31 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/13 14:23:26 by apolo-to         ###   ########.fr       */
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

/**
 * This function moves a num from top half stack to the top using rotate
 * Then push the number to target stack 'a' or 'b' using push.
 * @param	t_stack* s_a	: The A stack.
 * @param	t_stack* s_b	: The B stack.
 * @param	int num_pos		: The position of number.
 * @param	char tar		: The target stack
 * @return	void
*/
void	up_num_from_top(t_stack **s_a, t_stack **s_b, int num_pos, char tar)
{
	while (num_pos > 1)
	{
		if (tar == 'a')
			ft_rotate_b(s_b);
		else
			ft_rotate_a(s_a);
		num_pos--;
	}
	if (tar == 'a')
		ft_push_a(s_a, s_b);
	else
		ft_push_b(s_a, s_b);
}

/**
 * This function moves a num from bottom half stack to the top using rotate
 * Then push the number to target stack 'a' or 'b' using push.
 * @param	t_stack* s_a	: The A stack.
 * @param	t_stack* s_b	: The B stack.
 * @param	int num_pos		: The position of number.
 * @param	char tar		: The target stack
 * @return	void
*/
void	up_num_from_bot(t_stack **s_a, t_stack **s_b, int num_pos, char tar)
{
	while (num_pos <= ft_get_stack_size(*s_a))
	{
		if (tar == 'b')
			ft_rev_rotate_a(s_a);
		else
			ft_rev_rotate_b(s_b);
		num_pos++;
	}
	if (tar == 'b')
		ft_push_b(s_a, s_b);
	else
		ft_push_a(s_a, s_b);
}
