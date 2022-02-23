/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:06:40 by dgallo-p          #+#    #+#             */
/*   Updated: 2022/02/23 13:01:05 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
		C LIBRARIES
*/

/*to write, read, close, access, pipe, dup, dup2, execve, fork*/
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/*malloc, free, exit*/
# include <stdlib.h>

/*open, unlink*/
# include <fcntl.h>

/*waitpid, wait*/
# include <sys/wait.h>

/*strerror*/
# include <string.h>

/*to perror*/
# include <stdio.h>

/*
		ERROR_MSG
*/
# define ERR_EXMPL "./pipex infile command1 command2 outfile\n"
# define ERR_INPUT "Invalid number of arguments: "
# define ERR_INFILE "Error on infile"
# define ERR_OUTFILE "Error on outfile"
# define ERR_COMMD "Command not found: "

/*
		STRUCTURE
*/

struct s_my_struct
{
	int		fd[2];
	int		status;
	char	*path;
	char	**paths;
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
	char	**args;
	char	*commd;
} my_pipex;

/*
		FUNCTIONS
*/

/*
	Libft functions
*/
char				**ft_split(char const *s, char c);
unsigned long int	ft_strlen(char const	*s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
/*
	Treat functions
*/
void				treat_argvs(int argc, char **argv);
char				*treat_commd(char *commd);
/*
	Child functions
*/
void				first_child(char **argv, char *envp[]);
void				second_child(char **argv, char *envp[]);
/*
	Path funtion
*/
void				get_path(char **envp);
/*
	Free functions
*/
void				free_struct(void);
void				free_args(char **args);
/*
	Error_msg
*/
void				werror(char *err);
void				werror2(char *commd);
void				check_pid(int status);
#endif
