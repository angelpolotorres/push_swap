/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:49:02 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/19 16:25:41 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This returns the smallest number in stack.
 * @param	t_stack* stack	: Stack to check.
 * @return	int				: The smallest number.
*/
int	ft_get_smallest_num(t_stack **stack)
{
	t_stack	*aux;
	int		smallest_num;

	aux = *stack;
	smallest_num = aux->a_num;
	while (aux)
	{
		if (aux->a_num < smallest_num)
			smallest_num = aux->a_num;
		aux = aux->next;
	}
	return (smallest_num);
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
 * This returns the biggest number in stack.
 * @param	t_stack* stack	: Stack to check.
 * @return	int				: The biggest number.
*/
int	ft_get_biggest_num(t_stack **stack)
{
	t_stack	*aux;
	int		biggest_num;

	aux = *stack;
	biggest_num = aux->a_num;
	while (aux)
	{
		if (aux->a_num > biggest_num)
			biggest_num = aux->a_num;
		aux = aux->next;
	}
	return (biggest_num);
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
