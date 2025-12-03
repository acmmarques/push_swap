/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:57:02 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/03 11:49:39 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_add_whitespaces(const char *str, int *i)
{
	while (str[*i] == ' '
		|| (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	res;

	sign = 1;
	i = 0;
	ft_add_whitespaces(str, &i);
	if ((str[i] == '-' || str[i] == '+')
		&& (ft_isdigit(str[i + 1])))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

void	free_stack_matrix_and_perror(t_stack_node **a, char **tokens)
{
	free_array(tokens, array_len(tokens));
	free_stack(a);
	print_error();
	exit(1);
}
