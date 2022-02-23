/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:26:24 by dgallo-p          #+#    #+#             */
/*   Updated: 2022/02/04 12:31:25 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_struct(void)
{
	close(my_pipex.infile);
	close(my_pipex.outfile);
}

void	free_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i] != '\0' )
		free(args[i]);
}
