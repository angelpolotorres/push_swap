/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:53:46 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/11 11:25:08 by apolo-to         ###   ########.fr       */
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
	int		arg;

	arg = 0;
	stack_a = NULL;
	if (argc == 1 || !ft_strlen(argv[1]))
		ft_exit(E_PARAMS_NOT_FOUND);
	while (++arg < argc)
		ft_parse_str_to_num(argv[arg], &stack_a);

	// Si no hay error y no esta ordenada -> ordenar
	// Liberar stack
	ft_print_stack(stack_a);
	return (0);
}
