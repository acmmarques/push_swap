/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:06:18 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/05 01:21:49 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				stack_size;

	a = NULL;
	b = NULL;
	init_stack_a(&a, argc, argv);
	stack_size = list_len(&a);
	print_ll(a);
	set_index(a);
	if (is_stack_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (stack_size == 2)
		sa(&a);
	else if (stack_size == 3)
		sort_three(&a);
	else if (stack_size <= 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	print_ll(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
