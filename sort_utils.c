/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:29:16 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/05 01:12:00 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_index(t_stack_node *stack)
{
	t_stack_node	*current_node;
	t_stack_node	*compare_node;

	current_node = stack;
	while (current_node)
	{
		current_node->index = 0;
		compare_node = stack;
		while (compare_node)
		{
			if (compare_node->value < current_node->value)
				current_node->index++;
			compare_node = compare_node->next;
		}
		current_node = current_node->next;
	}
}

t_stack_node	*find_smallest_node(t_stack_node *a)
{
	t_stack_node	*head;
	t_stack_node	*smallest;

	head = a;
	smallest = a;
	while (head)
	{
		if (head->index < smallest->index)
			smallest = head;
		head = head->next;
	}
	return (smallest);
}

int	get_node_position(t_stack_node *a)
{
	int	i;

	i = 0;
	while (a->prev)
	{
		i++;
		a = a->prev;
	}
	return (i);
}
