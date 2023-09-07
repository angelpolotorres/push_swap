/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:53:46 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/07 11:07:27 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	t_number	*stack_a;
	int			arg;
	int			error;

	stack_a = NULL;
	arg = 1;
	error = 0;

	while (arg < argc)
	{
		if(!ft_parse_input(argv[arg], &stack_a))
		{
			ft_printf("Error\n");
			error = E_INVAL_PARAM;
			break;
		}
		arg++;
	}
	// Si no hay error y no esta ordenada -> ordenar
	// Liberar stack
	return (error);
}
