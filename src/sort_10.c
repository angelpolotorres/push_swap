/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:41:40 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/12 16:03:29 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_smallest_pos(t_stack **stack)
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
		if(aux->a_num < smallest_num)
		{
			smallest_num = aux->a_num;
			smallest_pos = i;
		}
		aux = aux->next;
		i++;
	}
	return (smallest_pos);
}

void	ft_mov_num_to_top(t_stack **stack_a, t_stack **stack_b, int num_pos)
{
	while (num_pos > 1)
	{
		ft_rotate_a(stack_a);
		num_pos--;
	}
	ft_push_b(stack_a, stack_b);
}

void	ft_mov_num_to_bottom(t_stack **stack_a, t_stack **stack_b, int num_pos)
{
	while (num_pos < ft_get_stack_size(*stack_a))
	{
		ft_rev_rotate_a(stack_a);
		num_pos++;
	}
	ft_push_b(stack_a, stack_b);
}

void	ft_sort_10(t_stack **stack_a, t_stack **stack_b)
{
	//ft_push_b(stack_a, stack_b);
	// printf("Stack A size-> %i\n", ft_get_stack_size(*stack_a));
	// printf("Stack B size-> %i\n", ft_get_stack_size(*stack_b));

	// int	num_pos;

	(void) stack_b;
	printf("Stack A ->\n");
	ft_print_stack(*stack_a);
	printf("El menor num esta en la pos-> %i\n", ft_get_smallest_pos(stack_a));


	// while (ft_get_stack_size(*stack_a) > 3)
	// {
	// 	num_pos = ft_get_smallest_pos(stack_a);
	// 	if (num_pos <= (ft_get_stack_size(*stack_a) / 2))
	// 		ft_mov_num_to_top(stack_a, stack_b, num_pos);
	// 	else
	// 		ft_mov_num_to_bottom(stack_a, stack_b, num_pos);
	// }


	// if (!ft_is_stack_sorted(*stack_a))
	// 	ft_sort_3(stack_a);
	// printf("Stack A ->\n");
	// ft_print_stack(*stack_a);
	// printf("Stack B ->\n");
	// ft_print_stack(*stack_b);
	
	// ft_push_a(stack_a, stack_b);
	// printf("Stack A size-> %i\n", ft_get_stack_size(*stack_a));
	// printf("Stack B size-> %i\n", ft_get_stack_size(*stack_b));
	// if (ft_get_stack_size(*stack_b) == 0)
	// 		printf("Stack B esta a %i\n", ft_get_stack_size(*stack_b));

	// while (ft_get_stack_size(*stack_b) != 0)
	// 	ft_push_a(stack_a, stack_b);
}
