/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:06:58 by dgallo-p          #+#    #+#             */
/*   Updated: 2022/02/23 13:14:21 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	get_path(envp);
	treat_argvs(argc, argv);
	pipe(my_pipex.fd);
	my_pipex.pid1 = fork();
	if (my_pipex.pid1 == 0)
		first_child(argv, envp);
	my_pipex.pid2 = fork();
	if (my_pipex.pid2 == 0)
		second_child(argv, envp);
	close(my_pipex.fd[0]);
	close(my_pipex.fd[1]);
	waitpid(my_pipex.pid1, &my_pipex.status, 0);
	check_pid(my_pipex.status);
	waitpid(my_pipex.pid2, &my_pipex.status, 0);
	check_pid(my_pipex.status);
	free_struct();
	return (0);
}
