/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:49:02 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/13 15:12:25 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/**
 * This ft count the stack size.
 * @param	t_stack* stack	: Stack to check.
 * @return	int				: The size stack.
*/
int	ft_get_stack_size(t_stack *stack)
{
	t_stack	*node;
	int		list_size;

	list_size = 1;
	node = stack;
	if (node == NULL)
		return (0);
	while (node->next != NULL)
	{
		list_size++;
		node = node->next;
	}
	return (list_size);
}

/**
 * This returns the smallest number position in stack.
 * @param	t_stack* stack	: Stack to check.
 * @return	int				: The smallest number position.
*/
int	ft_get_smallest_num_pos(t_stack **stack)
{
	t_stack	*aux;
	int		smallest_pos;
	int		smallest_num;
	int		i;

	smallest_pos = 0;
	i = 1;
	aux = *stack;
	smallest_num = (*stack)->a_num;
	while (aux != NULL)
	{
		if (aux->a_num < smallest_num)
		{
			smallest_num = aux->a_num;
			smallest_pos = i;
		}
		aux = aux->next;
		i++;
	}
	return (smallest_pos);
}

/**
 * This returns the biggest number position in stack.
 * @param	t_stack* stack	: Stack to check.
 * @return	int				: The biggest number position.
*/
int	ft_get_biggest_num_pos(t_stack **stack)
{
	t_stack	*aux;
	int		biggest_pos;
	int		biggest_num;
	int		i;

	biggest_pos = 0;
	i = 1;
	aux = *stack;
	biggest_num = (*stack)->a_num;
	while (aux != NULL)
	{
		if (aux->a_num > biggest_num)
		{
			biggest_num = aux->a_num;
			biggest_pos = i;
		}
		aux = aux->next;
		i++;
	}
	return (biggest_pos);
}

// DELETE
void	ft_print_stack(t_stack *stack)
{
	t_stack	*current_num;

	current_num = stack;
	while (current_num != NULL)
	{
		printf("%i - (%i)\n", current_num->num, current_num->a_num);
		current_num = current_num->next;
	}
}
// DELETE
