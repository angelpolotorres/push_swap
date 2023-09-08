/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:19 by apolo-to          #+#    #+#             */
/*   Updated: 2023/09/08 12:05:23 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>

enum	e_error
{
	NO_ERROR = 0,
	ERROR = -1,
	E_INVALID_PARAM = 2,
	E_PARAMS_NOT_FOUND = 3,
	E_INT_LIMITS_EXCEEDED = 4,
};

typedef struct s_number
{
	int				number;
	int				alias_num;
	struct s_number	*next;
}	t_number;

int	ft_parse_input(const char *str, t_number **stack_a);
#endif