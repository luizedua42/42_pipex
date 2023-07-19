/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:54:49 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:24 by luizedua         ###   ########.fr       */
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

char	*get_command(char *command, char **ev)
{
	char	*cmd;
	char	*tmp;
	char	**paths;
	int		i;

	i = 0;
	paths = get_path(ev);
	while (paths[i] != NULL)
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(tmp, command);
		free(tmp);
		if (!access(cmd, F_OK) && !access(cmd, X_OK))
		{
			ft_free((void **)paths);
			return (cmd);
		}
		free(cmd);
		i++;
	}
	ft_free((void **)paths);
	return (NULL);
}

char	**split_flags(char *str)
{
	char	**cmd_param;

	cmd_param = ft_split(str, ' ');
	return (cmd_param);
}
