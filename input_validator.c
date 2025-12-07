/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:47:48 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/04 22:45:12 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_argument_number_and_empty_strs(int argc, char **argv)
{
	int	i;
	int	j;
	int	has_nospace;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (print_error(), 0);
		j = 0;
		has_nospace = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				has_nospace = 1;
			j++;
		}
		if (!has_nospace)
			return (print_error(), 0);
		i++;
	}
	return (1);
}

static char	**fill_tokens(char **argv)
{
	char	**matrix;
	char	*huge_str;
	int		i;

	huge_str = ft_strdup("");
	if (!huge_str)
		return (print_error(), NULL);
	i = 1;
	while (argv[i])
	{
		huge_str = ft_strjoin_free(huge_str, argv[i]);
		if (!huge_str)
			return (print_error(), NULL);
		i++;
	}
	matrix = ft_split(huge_str, ' ');
	if (!matrix)
	{
		free(huge_str);
		print_error();
		exit(1);
	}
	free(huge_str);
	return (matrix);
}

char	**parse_input(int argc, char **argv)
{
	char	**tokens;

	if (!validate_argument_number_and_empty_strs(argc, argv))
		exit (1);
	tokens = fill_tokens(argv);
	if (!tokens)
	{
		print_error();
		exit (1);
	}
	return (tokens);
}
