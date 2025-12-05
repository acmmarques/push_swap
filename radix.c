/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:22:36 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/05 01:02:27 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bits_number(t_stack_node **stack)
{
	t_stack_node	*head;
	int				max;
	int				bits_number;

	head = *stack;
	max = head->index;
	bits_number = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> bits_number) != 0)
		bits_number++;
	return (bits_number);
}

int	list_len(t_stack_node **stack)
{
	t_stack_node	*head;
	int				i;

	head = *stack;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}


void	sort_three(t_stack_node **a)
{
	a = a;
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	a = a;
	b = b;
}

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*head_a;
	int				i;
	int				j;
	int				size;
	int				bits_number;

	i = 0;
	head_a = *a;
	size = list_len(a);
	bits_number = get_bits_number(a);
	while (i < bits_number)
	{
		j = 0;
		while (j < size)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (list_len(b) != 0)
			pa(a, b);
		i++;
	}
}
