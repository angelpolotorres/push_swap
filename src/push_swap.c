/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:53:46 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/06 17:21:17 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include "gnl.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	t_number	*stack_a;
	int			param;
	int			error;

	stack_a = NULL;
	param = 1;
	error = 0;

	while (param < argc)
	{
		if(!ft_parse_input(argv[param], &stack_a))
		{
			ft_printf("Error\n");
			error = E_INVAL_PARAM;
			break;
		}
	}
	return (error);
}
