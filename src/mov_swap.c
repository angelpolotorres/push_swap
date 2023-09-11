/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:12:01 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/11 16:17:29 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * This ft take the top and semitop number of the A pile and swap them.
 * Later prints "sa" in console.
 * @param t_stack** stack_a		: The stack.
 * @return void
*/
void	ft_swap_a(t_stack **stack)
{
	t_stack	*top_num;
	t_stack	*bot_num;
	t_stack	*aux;

	top_num = *stack;
	bot_num = top_num->next;
	aux = bot_num->next;
	bot_num->next = top_num;
	top_num->next = aux;
	*stack = bot_num;
	ft_printf("sa\n");
}

/**
 * This ft take the top and semitop number of the B pile and swap them.
 * Later print "sb" in console.
 * @param t_stack** stack_b		: The stack.
 * @return void
*/
void	ft_swap_b(t_stack **stack)
{
	t_stack	*top_num;
	t_stack	*bot_num;
	t_stack	*aux;

	top_num = *stack;
	bot_num = top_num->next;
	aux = bot_num->next;
	bot_num->next = top_num;
	top_num->next = aux;
	*stack = bot_num;
	ft_printf("sb\n");
}
