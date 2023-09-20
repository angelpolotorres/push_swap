/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:08:05 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/20 08:44:25 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"

/**
 * This ft exits the program returning the number of error.
 * Error types are specified in the header file push_swap.h
 * @param int error_type	: The number of error.
 * @return void
*/
void	ft_exit(int error_type)
{
	int	error;

	error = 0;
	if (error_type != 0)
		error = error_type;
	exit(error);
}

/**
 * This ft prints "Error" and calls ft_exit to exit the program.
 * Error types are specified in the header file push_swap.h
 * @param int error_type	: The number of error.
 * @return void
*/
void	ft_exit_error(int error_type)
{
	ft_printf("Error\n");
	ft_exit(error_type);
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
 * This ft calls ft_free and ft_exit_error.
 * @param t_stack* stack	: The stack to free.
 * @param int error_type	: The number of error.
 * @return void
*/
void	ft_free_exit_error(t_stack *stack, int error_type)
{
	ft_free(stack);
	ft_exit_error(error_type);
}
