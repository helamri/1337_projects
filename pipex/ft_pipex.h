/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 13:54:14 by helamri           #+#    #+#             */
/*   Updated: 2019/02/03 20:59:34 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef struct		s_pipex
{
	char			*file1;
	char			*cmd1;
	char			*file2;
	char			*cmd2;
}					t_pipex;

typedef struct		s_fd
{
	int				fd1;
	int				fd2;
}					t_fd;

int					ft_exist(char **av, char **env, t_pipex *pipex, t_fd *fd);

#endif
