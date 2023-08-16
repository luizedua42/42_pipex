/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:35:24 by luizedua          #+#    #+#             */
/*   Updated: 2023/08/16 14:00:32 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	close_fds(t_pipex *ppx)
{
	close(ppx->pipefd[0]);
	close(ppx->pipefd[1]);
	close(ppx->flfd[0]);
	close(ppx->flfd[1]);
}

void	child_process_one(int *flfd, int *pipefd, t_pipex *pipex)
{
	dup2(flfd[0], 0);
	dup2(pipefd[1], 1);
	close_fds(pipex);
	execve(pipex->fcmd, pipex->param1, pipex->ambient);
	ft_putstr_fd("execve error\n", 2);
	ft_free((void **)pipex->param1);
	ft_free((void **)pipex->param2);
	free(pipex->fcmd);
	free(pipex->scmd);
	exit(0);
}

void	child_process_two(int *flfd, int *pipefd, t_pipex *pipex)
{
	dup2(pipefd[0], 0);
	dup2(flfd[1], 1);
	close_fds(pipex);
	execve(pipex->scmd, pipex->param2, pipex->ambient);
	ft_putstr_fd("execve error\n", 2);
	exit(0);
}

void	ft_free(void **matrix)
{
	int	i;

	i = 0;
	while (matrix != NULL && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

int	main(int argc, char *argv[], char **envp)
{
	char	*cmd1;
	char	*cmd2;
	t_pipex	ppx;

	if (argc != 5)
		return (2);
	ppx.flfd[0] = open(argv[1], O_RDONLY);
	if (ppx.flfd[0] == -1)
	{
		ft_putstr_fd("infile does not exit\n", 2);
		return (2);
	}
	ppx.flfd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipe(ppx.pipefd) == -1)
		ft_putstr_fd("pipe error", 2);
	ppx.param1 = split_flags(argv[2]);
	ppx.param2 = split_flags(argv[3]);
	cmd1 = get_command(ppx.param1[0], envp, &ppx);
	cmd2 = get_command(ppx.param2[0], envp, &ppx);
	make_it_work(cmd1, cmd2, envp, &ppx);
	ft_free((void **)ppx.param1);
	ft_free((void **)ppx.param2);
	free(cmd1);
	free(cmd2);
	return (0);
}
