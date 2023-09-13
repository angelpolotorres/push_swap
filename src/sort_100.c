/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:37:38 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/13 16:05:26 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_smallest_num(t_stack **stack)
{
	t_stack	*aux;
	int		smallest_num;

	aux = *stack;
	smallest_num = aux->a_num;
	while (aux->next != NULL)
	{
		if(aux->a_num < smallest_num)
			smallest_num = aux->a_num;
		aux = aux->next;
	}
	return (smallest_num);
}

void	ft_push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int smallest_num)
{
	t_stack	*aux;
	int		i;

	aux = *stack_a;
	i = smallest_num;
	while(i > 0)
	{
		if (aux->a_num <= smallest_num)
		{
			ft_push_b(stack_a, stack_b);
			i--;
		}
		else
			ft_rotate_a(stack_a);
	}
}

void	ft_sort_100(t_stack **stack_a, t_stack **stack_b, int biggest_num)
{
	int	size_chunk;
	int	biggest_pos;
	int	smallest_num;

	smallest_num = 1;
	biggest_pos = ft_get_biggest_num_pos(stack_a);
	size_chunk = biggest_num / 4;
	while (ft_get_stack_size(*stack_a) > 0)
	{
		ft_push_chunk_to_b(stack_a, stack_b, smallest_num);
		smallest_num = smallest_num + size_chunk;
	}
}