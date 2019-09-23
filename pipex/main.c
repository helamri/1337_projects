/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:17:35 by helamri           #+#    #+#             */
/*   Updated: 2019/02/03 20:55:33 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int			ft_run(char **av, char **env, t_fd *fd, t_pipex *pipex)
{
	int				pipe_fd[2];
	char			**command1;
	char			**command2;

	command1 = ft_strsplit(av[2], ' ');
	command2 = ft_strsplit(av[3], ' ');
	pipe(pipe_fd);
	if ((fork()) > 0)
	{
		dup2(fd->fd1, 0);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		execve(pipex->cmd1, command1, env);
		return (0);
	}
	if (fork() == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		dup2(fd->fd2, 1);
		execve(pipex->cmd2, command2, env);
		return (1);
	}
	return (0);
}

int					main(int ac, char **av, char **env)
{
	t_pipex			*pipex;
	t_fd			*fd;

	if (ac != 5)
	{
		ft_putendl("Error");
		return (-1);
	}
	if (!(pipex = (t_pipex *)malloc(sizeof(*pipex)))
			|| !(fd = (t_fd *)malloc(sizeof(*fd))))
		return (-1);
	if (ft_exist(av, env, pipex, fd) == -1)
		return (-1);
	ft_run(av, env, fd, pipex);
	return (0);
}
