/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:54:04 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/28 14:56:40 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_argument(t_info *info, char **av, char **ev)
{
	info->command_in = ft_split(av[2], ' ');
	info->command_out = ft_split(av[3], ' ');
	info->path_command_in = get_path(info->command_in[0], ev);
	info->path_command_out = get_path(info->command_out[0], ev);
	if (info->path_command_in == NULL || info->path_command_out == NULL)
	{
		write(1, "Not a valid command.\n", 22);
		return (0);
	}
	info->fd_infile = open(av[1], O_RDONLY);
	info->fd_outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (info->fd_infile == -1 || info->fd_outfile == -1)
	{
		write(1, "Not a valid file.\n", 19);
		return (0);
	}
	info->argument_array_in = join_array(info->path_command_in,
			info->command_in + 1);
	info->argument_array_out = join_array(info->path_command_out,
			info->command_out + 1);
	return (1);
}

char	*get_path(char *cmd, char **ev)
{
	int		i;
	int		j;
	char	*command;
	char	*path;

	command = ft_strjoin("/", cmd);
	i = 0;
	while (ev[i] != NULL)
	{
		if (ft_strncmp(ev[i], "PATH=", 5) == 0)
		{
			path = get_command_path(ev[i], command);
			if (path != NULL)
				break ;
		}
		i++;
	}
	free(command);
	command = NULL;
	return (path);
}

char	*get_command_path(char *ev, char *command)
{
	char	*result;
	char	**path_array;
	int		i;

	path_array = ft_split(ev + 5, ':');
	i = 0;
	while (path_array[i] != NULL)
	{
		result = ft_strjoin(path_array[i], command);
		if (access(result, F_OK) == 0)
		{
			free_array(&path_array);
			return (result);
		}
		free(result);
		result = NULL;
		i++;
	}
	free_array(&path_array);
	return (NULL);
}
