/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:43:41 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/19 11:59:10 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This ft add a node to the beginning of stack.
 * @param	t_stack** stack		: Target stack.
 * @param	t_stack* node		: The node to add.
 * @return	void
*/
void	ft_add_node_beginning_stack(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	*stack = node;
}

/**
 * This ft add a node to the end of stack.
 * @param	t_stack** stack		: Target stack.
 * @param	t_stack* node		: The node to add.
 * @return	void
*/
void	ft_add_node_end_stack(t_stack **stack, t_stack *node)
{
	t_stack	*aux;

	aux = *stack;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	else
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = node;
	}
}

/**
 * This ft return a pointer to the last stack node.
 * @param	t_stack* stack		: Stack to check.
 * @return	t_stack* last_node	: Pointer to the last node.
*/
t_stack	*ft_get_last_stack_node(t_stack *stack)
{
	t_stack	*last_node;

	last_node = stack;
	while (last_node)
	{
		if (last_node->next == NULL)
			break ;
		last_node = last_node->next;
	}
	return (last_node);
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
 * This function counts numbers smaller than limit_num.
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
int	ft_nums_under_limit(t_stack **stack_a, int limit_num)
{
	t_stack	*aux;
	int		count;

	aux = *stack_a;
	count = 0;
	while (aux)
	{
		if (aux->a_num <= limit_num)
			count++;
		aux = aux->next;
	}
	return (count);
}
