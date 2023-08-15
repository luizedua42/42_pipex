/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:54:49 by luizedua          #+#    #+#             */
/*   Updated: 2023/08/15 14:02:35 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char *s1, char *s2, char **e1, t_pipex *pip)
{
	pip->ambient = e1;
	pip->fcmd = s1;
	pip->scmd = s2;
}

char	**get_path(char **envp)
{
	char	**str;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	str = ft_split(*envp + 5, ':');
	return (str);
}

char	*get_command(char *command, char **ev, t_pipex *pipex)
{
	char	*cmd;
	char	*tmp;
	int		i;

	i = 0;
	if (!command)
		return (NULL);
	if (command[0] == '/' || command[0] == '.')
		return (ft_strdup(command));
	pipex->paths = get_path(ev);
	while (pipex->paths[i] != NULL)
	{
		tmp = ft_strjoin(pipex->paths[i], "/");
		cmd = ft_strjoin(tmp, command);
		free(tmp); 
		if (!access(cmd, F_OK) && !access(cmd, X_OK))
		{
			ft_free((void **)pipex->paths);
			return (cmd);
		}
		free(cmd);
		i++;
	}
	ft_free((void **)pipex->paths);
	return (NULL);
}

char	**split_flags(char *str)
{
	char	**cmd_param;

	cmd_param = ft_split(str, ' ');
	return (cmd_param);
}

void	make_it_work(char *cmd1, char *cmd2, char **env, t_pipex *ppx)
{
	int	pid[2];

	pipex(cmd1, cmd2, env, ppx);
	if (cmd1 != NULL)
	{
		pid[0] = fork();
		if (pid[0] < 0)
			ft_putstr_fd("error fork 1\n", 2);
		if (pid[0] == 0)
			child_process_one(ppx->flfd, ppx->pipefd, ppx);
	}
	else
		ft_putstr_fd("command not found\n", 2);
	if(cmd2 != NULL)
	{
		pid[1] = fork();
		if (pid[1] < 0)
			ft_putstr_fd("error fork 2\n", 2);
		if (pid[1] == 0)
			child_process_two(ppx->flfd, ppx->pipefd, ppx);
	}
	else
		ft_putstr_fd("command not found\n", 2);
	wait(NULL);
	close_fds(ppx);
}
