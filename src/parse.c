/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:09:14 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/08 13:20:53 by apolo-to         ###   ########.fr       */
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

// int	ft_add_num_to_list(int	number)
// {
	
// }

int	ft_parse_input(const char *str_nums, t_number **stack_a)
{
	const char	*ptr_str_nums;
	int			chars_readed;

	ptr_str_nums = str_nums;
	chars_readed = ft_check_chars(ptr_str_nums);
	if (chars_readed == ERROR)
		return (ERROR);
	if (!ft_intlimits(ptr_str_nums))
		return (ERROR);
	ft_printf("%i\n", ft_atoi(ptr_str_nums));
	ptr_str_nums = ptr_str_nums + chars_readed;
	if (*ptr_str_nums != '\0')
		return (ft_parse_input(ptr_str_nums, stack_a));
	return (1);
}
