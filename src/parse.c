/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:09:14 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/07 12:57:11 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	*ft_check_chars(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0' && !ft_isspace(str[i]))
	{
		if (!ft_isdigit(str[i]) || !ft_isposneg(str[i]))
			return (0);
		if (ft_isposneg(str[i]) && (ft_isposneg(str[i + 1])))
			return (0);
		if (ft_isposneg(str[i]) && ft_isspace(str[i + 1]))
			return (0);
		printf("%c\n", str[i]);
		i++;
	}
	return (&str[i]);
}

int	ft_parse_input(char *arg, t_number **stack_a)
{
	(void) arg;
	(void) stack_a;

	while (ft_isspace(*arg))
	{
		printf("Espacio\n");
		arg++;
	}
	printf("%c\n", *arg);

	//arg = ft_check_chars(arg);
	// if (!arg)
	// 	return (0);
	// if (*arg != '\0')
	// 	return (ft_parse_input(arg, stack_a));
	return (1);
}