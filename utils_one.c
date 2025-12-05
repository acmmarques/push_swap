/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:23:31 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/05 01:21:43 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*dest_ptr;
	const unsigned char		*src_ptr;

	if (!dest && !src)
		return (dest);
	dest_ptr = dest;
	src_ptr = src;
	while (n--)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
	}
	return (dest);
}

static char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	total_size;
	char	*concat_str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_size = len_s1 + len_s2 + 1;
	concat_str = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!concat_str)
		return (NULL);
	ft_memcpy(concat_str, s1, len_s1);
	ft_memcpy(concat_str + len_s1, s2, len_s2);
	concat_str[total_size - 1] = ' ';
	concat_str[total_size] = '\0';
	return (concat_str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	free(s1);
	return (new_str);
}

char	*ft_strdup(const char *s1)
{
	size_t	str_len;
	char	*dest;

	str_len = ft_strlen(s1);
	dest = (char *)malloc((str_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, str_len + 1);
	return (dest);
}
