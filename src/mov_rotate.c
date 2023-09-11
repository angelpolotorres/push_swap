/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:22:50 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/11 16:31:55 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * 
*/
void	ft_rotate_a(t_stack **stack)
{
	t_stack	*top_num;
	t_stack	*semi_top_num;
	t_stack	*bottom_num;

	top_num = *stack;
	semi_top_num = top_num->next;
	bottom_num = semi_top_num->next;
	while (bottom_num->next != NULL)
		bottom_num = bottom_num->next;
	bottom_num->next = top_num;
	top_num->next = NULL;
	*stack = semi_top_num;
	ft_printf("ra\n");
}

void	ft_rev_rotate_a(t_stack **stack)
{
	t_stack	*top_num;
	t_stack	*semi_bot_num;
	t_stack	*bot_num;

	top_num = *stack;
	semi_bot_num = top_num->next;
	while (semi_bot_num->next->next != NULL)
		semi_bot_num = semi_bot_num->next; 
	bot_num = semi_bot_num->next;
	bot_num->next = top_num;
	semi_bot_num->next = NULL;
	*stack = bot_num;
	ft_printf("rra\n");
}

void	ft_rotate_b(t_stack **stack)
{
	t_stack	*top_num;
	t_stack	*semi_top_num;
	t_stack	*bottom_num;

	top_num = *stack;
	semi_top_num = top_num->next;
	bottom_num = semi_top_num->next;
	while (bottom_num->next != NULL)
		bottom_num = bottom_num->next;
	bottom_num->next = top_num;
	top_num->next = NULL;
	*stack = semi_top_num;
	ft_printf("rb\n");
}

void	ft_rev_rotate_b(t_stack **stack)
{
	t_stack	*top_num;
	t_stack	*semi_bot_num;
	t_stack	*bot_num;

	top_num = *stack;
	semi_bot_num = top_num->next;
	while (semi_bot_num->next->next != NULL)
		semi_bot_num = semi_bot_num->next; 
	bot_num = semi_bot_num->next;
	bot_num->next = top_num;
	semi_bot_num->next = NULL;
	*stack = bot_num;
	ft_printf("rrb\n");
}
