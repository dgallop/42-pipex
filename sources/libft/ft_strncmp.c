/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:56:15 by dgallo-p          #+#    #+#             */
/*   Updated: 2022/02/02 13:05:39 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	dev;
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	dev = 0;
	i = 0;
	if (n == 0)
		return (0);
	while ((s3[i] || s4[i]) && (i < n - 1) && s3[i] == s4[i])
		i++;
	dev = s3[i] - s4[i];
	return (dev);
}
