/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:09:14 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/11 11:30:06 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static int	ft_check_chars(const char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] != '\0' && !ft_isspace(str[i]))
	{
		if (!ft_isdigit(str[i]) && !ft_isposneg(str[i]))
			ft_exit(E_INVALID_PARAM);
		if (ft_isposneg(str[i]) && ft_isposneg(str[i + 1]))
			ft_exit(E_INVALID_PARAM);
		if (ft_isposneg(str[i]) && str[i + 1] == '\0')
			ft_exit(E_INVALID_PARAM);
		if (ft_isposneg(str[i]) && ft_isspace(str[i + 1]))
			ft_exit(E_INVALID_PARAM);
		if (ft_isposneg(str[i]) && !ft_isspace(str[i + 1])
			&& ft_isposneg(str[i + 2]))
			ft_exit(E_INVALID_PARAM);
		i++;
	}
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

static t_stack	*ft_create_node_num(t_stack *stack_a, int number)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		ft_free_exit(stack_a, E_MALLOC_FAIL);
	new_node->num = number;
	new_node->a_num = 1;
	new_node->next = NULL;
	return (new_node);
}

static int	ft_add_num_to_list(t_stack **stack_a, int number)
{
	t_stack	*new_node;
	t_stack	*aux;

	new_node = ft_create_node_num(*stack_a, number);
	if (*stack_a == NULL)
		*stack_a = new_node;
	else
	{
		aux = *stack_a;
		if (aux->num > new_node->num)
			aux->a_num++;
		else
			new_node->a_num++;
		while (aux->next != NULL)
		{
			aux = aux->next;
			if (aux->num > new_node->num)
				aux->a_num++;
			else
				new_node->a_num++;
		}
		aux->next = new_node;
	}
	return (1);
}

static void	ft_is_num_repeated(t_stack *stack_a, int number)
{
	while (stack_a != NULL)
	{
		if (stack_a->num == number)
			ft_exit(E_INVALID_PARAM);
		stack_a = stack_a->next;
	}
}

void	ft_parse_str_to_num(const char *str, t_stack **stack_a)
{
	const char	*ptr_str;
	int			chars_readed;
	int			num;

	ptr_str = str;
	chars_readed = ft_check_chars(ptr_str);
	if (!ft_intlimits(ptr_str))
		ft_exit(E_INVALID_PARAM);
	num = ft_atoi(ptr_str);
	ft_is_num_repeated(*stack_a, num);
	ft_add_num_to_list(stack_a, num); 
	ptr_str = ptr_str + chars_readed;
	if (*ptr_str != '\0')
		return (ft_parse_str_to_num(ptr_str, stack_a));
}
