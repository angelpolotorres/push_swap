/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:53:46 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/20 16:09:23 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

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
	if (!ft_is_stack_sorted(stack_a))
		ft_sort_stack(&stack_a);
	ft_free(stack_a);
	return (0);
}
