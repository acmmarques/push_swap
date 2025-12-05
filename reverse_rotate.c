/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:12:56 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/04 17:25:56 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = find_last(*stack);
	(*stack)->prev = last;
	last->next = *stack;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
}

void	rra(t_stack_node **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
