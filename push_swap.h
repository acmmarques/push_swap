/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:18:20 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/04 16:08:53 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

//REMOVER DEPOIS
# include <stdio.h>
//FIM REMOVER DEPOIS

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

size_t	array_len(char **array);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_array(char **array, int height);
void	free_stack(t_stack_node **stack);
void	free_stack_matrix_and_perror(t_stack_node **a, char **tokens);
void	init_stack_a(t_stack_node **a, int argc, char **argv);
char	**parse_input(int argc, char **argv);
void	print_error(void);
t_stack_node	*find_last(t_stack_node *head);
void	sa(t_stack_node **stack);
void	sb(t_stack_node **stack);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);
void	pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	pb(t_stack_node **stack_a, t_stack_node **stack_b);
void	ra(t_stack_node **stack);
void	rb(t_stack_node **stack);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);

#endif
