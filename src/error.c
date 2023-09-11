/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:08:05 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/11 15:17:39 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"

/**
 * This ft prints "Error" and exit the program returning the number of error.
 * Error types are specified in the header file push_swap.h
 * @param int error_type	: The number of error.
 * @return void
*/
void	ft_exit(int error_type)
{
	ft_printf("Error\n");
	exit(error_type);
}

/**
 * This ft free the stack.
 * @param t_stack* stack	: Stack to free.
 * @return void
*/
void	ft_free(t_stack *stack)
{
	t_stack	*aux;

	while (stack != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}

/**
 * This ft calls ft_free and ft_exit.
 * @param t_stack* stack	: The stack to free.
 * @param int error_type	: The number of error.
 * @return void
*/
void	ft_free_exit(t_stack *stack, int error_type)
{
	ft_free(stack);
	ft_exit(error_type);
}
