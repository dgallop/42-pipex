/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:27:07 by dgallo-p          #+#    #+#             */
/*   Updated: 2022/02/23 13:17:39 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_path(char **envp)
{
	my_pipex.status = 0;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	my_pipex.path = (*envp + 5);
	my_pipex.paths = ft_split(my_pipex.path, ':');
}

char	*treat_commd(char *commd)
{
	char	*aux;
	char	*test;
	int		i;

	i = 0;
	while (my_pipex.paths[i] != NULL)
	{
		aux = ft_strjoin(my_pipex.paths[i], "/");
		test = ft_strjoin(aux, commd);
		free(aux);
		if (access(test, 0) == 0)
			return (test);
		free(test);
		i++;
	}
	werror2(commd);
	return (NULL);
}
