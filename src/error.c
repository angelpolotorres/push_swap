/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:08:05 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/09 10:57:05 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"

void	ft_exit(int error_type)
{
		ft_printf("Error\n");
		exit(error_type);
}

void	ft_free_exit(t_stack *stack, int error_type)
{
	t_stack *aux;

	while (stack != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
	ft_exit(error_type);
}
