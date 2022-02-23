/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:35:42 by dgallo-p          #+#    #+#             */
/*   Updated: 2022/02/04 12:38:15 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*ft_cpy(char *dst, const char *src,
				unsigned int dstsize, unsigned int *j)
{
	unsigned int	i;
	unsigned int	x;

	if (!dst || !src)
		return (0);
	i = 0;
	x = *j;
	while (src[x] && i < dstsize)
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	*j = x;
	return (dst);
}

static char	**ft_error(char **new)
{
	unsigned int	i;

	i = 0;
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free(new);
	return (0);
}

static unsigned int	ft_total_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	total_str;

	total_str = 0;
	i = 0;
	if (!s[0])
		return (0);
	while ((char)s[i] == c)
		i++;
	while (s[i])
	{
		if ((char)s[i] == c)
		{
			total_str++;
			while (s[i] && (char)s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		total_str++;
	return (total_str);
}

static unsigned int	ft_found_size(char const *s, char c, unsigned int j)
{
	unsigned int	size;

	size = 0;
	while ((char)s[j] == c && (char)s[j])
		j++;
	while ((char)s[j] && (char)s[j] != c)
	{
		size++;
		j++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char			**new;
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * ((ft_total_str(s, c)) + 1));
	if (!new)
		return (0);
	i = 0;
	j = 0;
	while (i < (ft_total_str(s, c)))
	{
		size = ft_found_size(s, c, j);
		new[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!new)
			return (ft_error(new));
		while (s[j] == c)
			j++;
		new[i] = ft_cpy(new[i], (char *)s, size, &j);
		i++;
	}
	new[i] = 0;
	return (new);
}
