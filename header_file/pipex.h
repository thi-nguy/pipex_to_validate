/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:27:11 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/28 14:30:17 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_info
{
	char	*path_command_in;
	char	*path_command_out;
	char	**command_in;
	char	**command_out;
	char	**argument_array_in;
	char	**argument_array_out;
	int		fd_infile;
	int		fd_outfile;
}	t_info;

void	pipex(char **av, char **ev);
void	free_memory(t_info *info);
void	execute_command(t_info *info, char **ev);
int		parse_argument(t_info *info, char **av, char **ev);
char	*get_path(char *cmd, char **ev);
char	*get_command_path(char *ev, char *command);
char	**join_array(char *element, char **tab);
int		count_tab(char **tab);
void	close_fd(int *fd1, int *fd2);

#endif
