/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:12:01 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/12 11:25:14 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * This ft swaps the top and semi-top elements of Stack A.
 * Then print "sa" on screen.
 * @param	t_stack** stack_a	: The stack A.
 * @return	void
*/
void	ft_swap_a(t_stack **stack_a)
{
	t_stack	*top_num;
	t_stack	*bot_num;
	t_stack	*aux;

	top_num = *stack_a;
	bot_num = top_num->next;
	aux = bot_num->next;
	bot_num->next = top_num;
	top_num->next = aux;
	*stack_a = bot_num;
	ft_printf("sa\n");
}

/**
 * This ft swaps the top and semi-top elements of Stack B.
 * Then print "sa" on the screen
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_swap_b(t_stack **stack_b)
{
	t_stack	*top_num;
	t_stack	*bot_num;
	t_stack	*aux;

	top_num = *stack_b;
	bot_num = top_num->next;
	aux = bot_num->next;
	bot_num->next = top_num;
	top_num->next = aux;
	*stack_b = bot_num;
	ft_printf("sb\n");
}

/**
 * This ft swaps the top and semi-top elements of Stack A and B.
 * Then print "sa" and "sb" on the screen
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
}
