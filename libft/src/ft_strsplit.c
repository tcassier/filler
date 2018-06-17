/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:42:00 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/05 00:26:37 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

void		free_tab(char **ptr)
{
	while (*ptr)
	{
		free(ptr);
		ptr++;
	}
	free(ptr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		nb_word;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	nb_word = ft_count_word(s, c);
	if (!(ptr = (char**)ft_memalloc(sizeof(char*) * (nb_word + 1))))
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(ptr[index] = ft_strsub(s, 0, ft_len(s, c))))
		{
			free_tab(ptr);
			ptr = NULL;
			return (NULL);
		}
		s = s + ft_len(s, c);
		index++;
	}
	ptr[index] = NULL;
	return (ptr);
}
