/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:09:14 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/08 17:06:52 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	ft_check_chars(const char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] != '\0' && !ft_isspace(str[i]))
	{
		if (!ft_isdigit(str[i]) && !ft_isposneg(str[i]))
			return (ERROR);
		if (ft_isposneg(str[i]) && ft_isposneg(str[i + 1]))
			return (ERROR);
		if (ft_isposneg(str[i]) && str[i + 1] == '\0')
			return (ERROR);
		if (ft_isposneg(str[i]) && ft_isspace(str[i + 1]))
			return (ERROR);
		if (ft_isposneg(str[i]) && !ft_isspace(str[i + 1])
			&& ft_isposneg(str[i + 2]))
			return (ERROR);
		i++;
	}
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

t_stack	*ft_create_node_num(int number)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->num = number;
	new_node->a_num = 1;
	new_node->next = NULL;
	return (new_node);
}

int	ft_add_num_to_list(t_stack **stack_a, int number)
{
	t_stack	*new_node;
	t_stack	*aux;

	new_node = ft_create_node_num(number);
	if(new_node == NULL)
		return (0);
	if (*stack_a == NULL)
		*stack_a = new_node;
	else
	{
		aux = *stack_a;
		while(aux->next != NULL)
		{
			if (aux->num > new_node->num)
				aux->a_num++;
			else
				new_node->a_num++;
			aux = aux->next;
		}
		aux->next = new_node;
	}
	return (1);
}

int	ft_parse_input(const char *str_nums, t_stack **stack_a)
{
	const char	*ptr_str_nums;
	int			chars_readed;

	ptr_str_nums = str_nums;
	chars_readed = ft_check_chars(ptr_str_nums);
	if (chars_readed == ERROR)
		return (ERROR);
	if (!ft_intlimits(ptr_str_nums))
		return (ERROR);
	if(!ft_add_num_to_list(stack_a, ft_atoi(ptr_str_nums)))
		return (ERROR);
	ptr_str_nums = ptr_str_nums + chars_readed;
	if (*ptr_str_nums != '\0')
		return (ft_parse_input(ptr_str_nums, stack_a));
	return (1);
}
