/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:35:33 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/19 09:00:18 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * This ft push down the stack A so the last element becomes the first one.
 * Then print "rra" on screen.
 * @param	t_stack** stack_a	: The stack A.
 * @return	void
*/
void	ft_rev_rotate_a(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*last_node;

	if (ft_get_stack_size(*stack_a) > 1)
	{
		aux = *stack_a;
		last_node = ft_get_last_stack_node(aux);
		while (aux->next != NULL && aux->next != last_node)
			aux = aux->next;
		aux->next = NULL;
		ft_add_node_beginning_stack(stack_a, last_node);
		ft_printf("rra\n");
	}
}

/**
 * This ft push down the stack B so the last element becomes the first one.
 * Then print "rrb" on screen.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_rev_rotate_b(t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*last_node;

	if (ft_get_stack_size(*stack_b) > 1)
	{
		aux = *stack_b;
		last_node = ft_get_last_stack_node(aux);
		while (aux->next != NULL && aux->next != last_node)
			aux = aux->next;
		aux->next = NULL;
		ft_add_node_beginning_stack(stack_b, last_node);
		ft_printf("rrb\n");
	}
}

/**
 * This ft push down the stack A so the last element becomes the first one.
 * Then repeat the process with Stack B.
 * Then print "rra" and "rrb" on screen.
 * @param	t_stack** stack_a	: The stack A.
 * @param	t_stack** stack_b	: The stack B.
 * @return	void
*/
void	ft_rev_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate_a(stack_a);
	ft_rev_rotate_b(stack_b);
}
