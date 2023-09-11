/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:21:12 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/11 16:28:07 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack_a)->a_num;
	mid = (*stack_a)->next->a_num;
	bot = (*stack_a)->next->next->a_num;
	if (top > mid && mid < bot && bot > top)
		ft_swap_a(stack_a);
	else if (top > mid && mid > bot && bot < top)
	{
		ft_swap_a(stack_a);
		ft_rev_rotate_a(stack_a);
	}
	else if (top > mid && mid < bot && bot < top)
		ft_rotate_a(stack_a);
	else if (top < mid && mid > bot && bot > top)
	{
		ft_swap_a(stack_a);
		ft_rotate_a(stack_a);
	}
	else if (top < mid && mid > bot && bot < top)
	{
		ft_rev_rotate_a(stack_a);
	}
}