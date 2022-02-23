/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:47:18 by dgallo-p          #+#    #+#             */
/*   Updated: 2022/02/23 13:16:50 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	werror(char *err)
{
	if (err == ERR_INPUT)
	{
		write(1, ERR_INPUT, ft_strlen(ERR_INPUT));
		write(1, ERR_EXMPL, ft_strlen(ERR_EXMPL));
	}
	else
		perror(err);
	exit(1);
}

void	werror2(char *commd)
{
	write(2, ERR_COMMD, ft_strlen(ERR_COMMD));
	write(2, commd, ft_strlen(commd));
	write(2, "\n", 1);
	exit(127);
}

void	check_pid(int status)
{
	if (WEXITSTATUS(status))
		exit(WEXITSTATUS(status));
}
