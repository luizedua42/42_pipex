/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:16:04 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/24 18:05:49 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// libs included
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>

//little structy
typedef struct s_pipex
{
	char	**param1;
	char	**paths;
	char	**param2;
	char	**ambient;
	char	*fcmd;
	char	*scmd;
	int		pipefd[2];
	int		flfd[2];
}			t_pipex;

//funcs

void		pipex(char *s1, char *s2, char **e1, t_pipex *pip);
char		**get_path(char **envp);
char		**split_flags(char *str);
char		*get_command(char *command, char **ev, t_pipex *pipex);
void		ft_free(void **matrix1);
void		child_process_two(int *flfd, int *pipefd, t_pipex *pipex);
void		child_process_one(int *flfd, int *pipefd, t_pipex *pipex);
void		make_it_work(char *cmd1, char *cmd2, char **env, t_pipex *ppx);


#endif
