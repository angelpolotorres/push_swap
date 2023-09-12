/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:22:50 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/12 11:57:34 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * This ft push up the stack A so the first element becomes the last one.
 * Then print "ra" on screen.
 * @param	t_stack** stack_a	: The stack A.
 * @return	void
*/
void	ft_rotate_a(t_stack **stack_a)
{
	t_stack	*top_num;
	t_stack	*semi_top_num;
	t_stack	*bottom_num;

	top_num = *stack_a;
	semi_top_num = top_num->next;
	bottom_num = semi_top_num->next;
	while (bottom_num->next != NULL)
		bottom_num = bottom_num->next;
	bottom_num->next = top_num;
	top_num->next = NULL;
	*stack_a = semi_top_num;
	ft_printf("ra\n");
}

/**
 * This ft push up the stack B so the first element becomes the last one.
 * Then print "rb" on screen.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_rotate_b(t_stack **stack_b)
{
	t_stack	*top_num;
	t_stack	*semi_top_num;
	t_stack	*bottom_num;

	top_num = *stack_b;
	semi_top_num = top_num->next;
	bottom_num = semi_top_num->next;
	while (bottom_num->next != NULL)
		bottom_num = bottom_num->next;
	bottom_num->next = top_num;
	top_num->next = NULL;
	*stack_b = semi_top_num;
	ft_printf("rb\n");
}

/**
 * This ft push up the stack A so the first element becomes the last one.
 * Repeat the process with Stack A.
 * Then print "ra" and "rb".
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
}
