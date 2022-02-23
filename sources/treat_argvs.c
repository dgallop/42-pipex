/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_argvs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:52:38 by kali              #+#    #+#             */
/*   Updated: 2022/02/23 13:14:09 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	treat_argvs(int argc, char **argv)
{
	if (argc != 5)
		werror(ERR_INPUT);
	my_pipex.infile = open(argv[1], O_RDONLY);
	if (my_pipex.infile < 0)
		werror(ERR_INFILE);
	my_pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (my_pipex.outfile < 0)
		werror(ERR_OUTFILE);
}

void	first_child(char **argv, char *envp[])
{
	dup2(my_pipex.fd[1], 1);
	close(my_pipex.fd[0]);
	dup2(my_pipex.infile, 0);
	my_pipex.args = ft_split(argv[2], ' ');
	my_pipex.commd = treat_commd(my_pipex.args[0]);
	execve(my_pipex.commd, my_pipex.args, envp);
	free_args(my_pipex.args);
	free(my_pipex.commd);
	exit(0);
}

void	second_child(char **argv, char *envp[])
{
	dup2(my_pipex.fd[0], 0);
	close(my_pipex.fd[1]);
	dup2(my_pipex.outfile, 1);
	my_pipex.args = ft_split(argv[3], ' ');
	my_pipex.commd = treat_commd(my_pipex.args[0]);
	execve(my_pipex.commd, my_pipex.args, envp);
	free_args(my_pipex.args);
	free(my_pipex.commd);
	exit(0);
}
