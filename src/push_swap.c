/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:53:46 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/08 17:12:55 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

// INICIO Borrar
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
// FIN Borrar

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int			error;
	int			arg;

	stack_a = NULL;
	error = NO_ERROR;
	if (argc == 1 || !ft_strlen(argv[1]))
	{
		ft_printf("Error\n");
		error = E_PARAMS_NOT_FOUND;
	}
	arg = 1;
	while (arg < argc)
	{
		if(ft_parse_input(argv[arg], &stack_a) == ERROR)
		{
			ft_printf("->Error\n");
			error = E_INVALID_PARAM;
			break;
		}
		arg++;
	}
	// Si no hay error y no esta ordenada -> ordenar
	// Liberar stack
	ft_print_stack(stack_a);
	return (error);
}
