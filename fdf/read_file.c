/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:50:47 by helamri           #+#    #+#             */
/*   Updated: 2019/01/27 19:57:23 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_x(int fd, char **line)
{
	int i;

	i = 0;
	while (get_next_line(fd, line))
		i++;
	close(fd);
	if (i == 0)
	{
		ft_putstr("Vide file");
		exit(0);
	}
	return (i);
}

int		get_y(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		open_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("Error : file not found");
		exit(0);
	}
	return (fd);
}

t_map	convert_file(char *file)
{
	t_map	map;

	map.i = 0;
	map.fd = open_file(file);
	map.height = get_x(map.fd, &map.line);
	map.fd = open_file(file);
	map.num = (int **)malloc(sizeof(int *) * map.height);
	while (get_next_line(map.fd, &map.line))
	{
		map.tab = ft_strsplit(map.line, ' ');
		map.width = get_y(map.tab);
		map.num[map.i] = (int *)malloc(sizeof(int) * map.width);
		map.width = 0;
		while (map.tab[map.width])
		{
			map.num[map.i][map.width] = ft_atoi(map.tab[map.width]);
			map.width++;
		}
		free(map.line);
		free(map.tab);
		map.i++;
	}
	return (map);
}
