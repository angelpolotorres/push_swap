/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:57:58 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/12 15:56:59 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_stack_size(t_stack *stack)
{
	t_stack	*node;
	int	list_size;

	list_size = 1;
	node = stack;
	while (node->next != NULL)
	{
		list_size++;
		node = node->next;
	}
	return (list_size);
}

/**
 * This ft checks if stack is sorted.
 * @param	t_stack* stack	: Stack to check.
 * @return	int				: (1)Sorted, (0)No sorted.
*/
int	ft_is_stack_sorted(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node != NULL)
	{
		if (node->next != NULL && node->a_num > node->next->a_num)
			return (NO_SORTED);
		node = node->next;
	}
	return (SORTED);
}

void	ft_sort_stack(t_stack **stack_a)
{
	int	stack_a_size;
	t_stack *stack_b;

	stack_a_size = ft_get_stack_size(*stack_a);
	if (stack_a_size == 2)
		ft_swap_a(stack_a);
	if (stack_a_size == 3)
		ft_sort_3(stack_a);
	if (stack_a_size > 3 && stack_a_size <= 10)
		ft_sort_10(stack_a, &stack_b);
	// si la lista tiene mas de 3 y menos o igual que 10 -> ordenar con 10
	// si la lista tiene más de 10 y menos de 100 -> ordenar con 100
	// si la lista tiene más de 100 y menos de 500 -> ordenar con 500
}