/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:21:12 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/12 12:44:28 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This ft sorts an stack with 3 numbers.
 * @param	t_stack** stack		: The stack to sort.
 * @return	void.
*/
void	ft_sort_3(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->a_num;
	mid = (*stack)->next->a_num;
	bot = (*stack)->next->next->a_num;
	if (top > mid && mid < bot && bot > top)
		ft_swap_a(stack);
	else if (top > mid && mid > bot && bot < top)
	{
		ft_swap_a(stack);
		ft_rev_rotate_a(stack);
	}
	else if (top > mid && mid < bot && bot < top)
		ft_rotate_a(stack);
	else if (top < mid && mid > bot && bot > top)
	{
		ft_swap_a(stack);
		ft_rotate_a(stack);
	}
	else if (top < mid && mid > bot && bot < top)
	{
		ft_rev_rotate_a(stack);
	}
}
