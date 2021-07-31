/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:51:54 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/28 14:53:59 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **ev)
{
	if (ac != 5)
	{
		write(1, "Wrong number of argument.\n", 25);
		return (0);
	}
	pipex(av, ev);
	return (0);
}

void	pipex(char **av, char **ev)
{
	t_info	info;

	ft_bzero(&info, sizeof(info));
	if (parse_argument(&info, av, ev) == 0)
		return ;
	if (info.fd_infile == -1 || info.fd_outfile == -1
		|| info.path_command_in == NULL || info.path_command_out == NULL)
	{
		free_memory(&info);
		return ;
	}
	execute_command(&info, ev);
	free_memory(&info);
}

void	free_memory(t_info *info)
{
	if (info->path_command_in != NULL)
	{
		free(info->path_command_in);
		info->path_command_in = NULL;
	}
	if (info->path_command_out != NULL)
	{
		free(info->path_command_out);
		info->path_command_out = NULL;
	}
	free_array(&info->command_in);
	free_array(&info->command_out);
	free_array(&info->argument_array_in);
	free_array(&info->argument_array_out);
}

void	execute_command(t_info *info, char **ev)
{
	int	pid1;
	int	pid2;
	int	fd[2];

	if (pipe(fd) == -1)
		return ;
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(info->fd_infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close_fd(&fd[0], &fd[1]);
		execve(info->path_command_in, info->argument_array_in, ev);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(info->fd_outfile, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close_fd(&fd[0], &fd[1]);
		execve(info->path_command_out, info->argument_array_out, ev);
	}
	close_fd(&fd[0], &fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
