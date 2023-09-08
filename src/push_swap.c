/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:53:46 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/08 10:36:16 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_number	*stack_a;
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
	return (error);
}
