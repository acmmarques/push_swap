/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 01:51:24 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/03 11:46:13 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	syntax_error(char *nbr_str)
{
	int	i;

	i = 0;
	if (!nbr_str[0])
		return (1);
	if (nbr_str[0] == '+' || nbr_str[0] == '-')
	{
		if (nbr_str[1] == '\0')
			return (1);
		i++;
	}
	while (nbr_str[i])
	{
		if (!ft_isdigit(nbr_str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	duplication_exists(t_stack_node *node, int nbr)
{
	if (!node)
		return (0);
	while (node)
	{
		if (node->value == nbr)
			return (1);
		node = node->next;
	}
	return (0);
}

int	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return (0);
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (0);
	node->value = nbr;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current_node;

	if (!stack)
		return ;
	current_node = *stack;
	while (current_node)
	{
		tmp = current_node->next;
		free(current_node);
		current_node = tmp;
	}
	*stack = NULL;
}

void	init_stack_a(t_stack_node **a, int argc, char **argv)
{
	char	**tokens;
	long	nbr;
	int		i;

	tokens = parse_input(argc, argv);
	i = 0;
	while (tokens[i])
	{
		if (syntax_error(tokens[i]))
			free_stack_matrix_and_perror(a, tokens);
		nbr = ft_atol(tokens[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_stack_matrix_and_perror(a, tokens);
		if (duplication_exists(*a, (int)nbr))
			free_stack_matrix_and_perror(a, tokens);
		if (!append_node(a, (int)nbr))
			free_stack_matrix_and_perror(a, tokens);
		i++;
	}
	free_array(tokens, array_len(tokens));
}
