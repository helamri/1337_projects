/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:12:12 by helamri           #+#    #+#             */
/*   Updated: 2019/02/03 20:33:56 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static char		*ft_file_exist(char *file)
{
	struct stat	*buf;

	if (!(buf = (struct stat *)malloc(sizeof(*buf))))
		return (NULL);
	if (stat(file, buf) == -1)
		return (NULL);
	return (file);
}

static char		**ft_find_paths(char **env)
{
	int			i;
	char		**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_strsplit(&env[i][5], ':');
		i++;
	}
	return (paths);
}

static char		*ft_command_exist(char *com, char **env)
{
	int			i;
	char		*str;
	char		**paths;
	char		**command;
	struct stat	*buf;

	command = ft_strsplit(com, ' ');
	paths = ft_find_paths(env);
	i = 0;
	if (!(buf = (struct stat *)malloc(sizeof(*buf))))
		return (NULL);
	while (paths[i])
	{
		if (!(str = (char *)malloc(sizeof(*str) * ft_strlen(paths[i]) + 1)))
			return (NULL);
		str = ft_strjoin(paths[i], "/");
		str = ft_strjoin(str, command[0]);
		if (stat(str, buf) == 0)
			return (str);
		if (stat(command[0], buf) == 0)
			return (command[0]);
		i++;
	}
	return (NULL);
}

int				ft_exist(char **av, char **env, t_pipex *pipex, t_fd *fd)
{
	pipex->file1 = ft_file_exist(av[1]);
	if (!(pipex->file2 = (char *)malloc(sizeof(char *))))
	{
		ft_putendl("Error");
		return (-1);
	}
	ft_strcpy(pipex->file2, av[4]);
	pipex->cmd1 = ft_command_exist(av[2], env);
	pipex->cmd2 = ft_command_exist(av[3], env);
	fd->fd1 = open(pipex->file1, O_RDONLY);
	fd->fd2 = open(pipex->file2, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IXUSR);
	if (fd->fd1 == -1 || fd->fd2 == -1 || !pipex->file1
			|| !pipex->cmd1 || !pipex->cmd2)
	{
		ft_putendl("Error");
		return (-1);
	}
	return (1);
}
