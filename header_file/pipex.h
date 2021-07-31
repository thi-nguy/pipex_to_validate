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

void		pipex(char **av, char **ev);
int	parse_argument(t_info *info, char **av, char **ev);
char 	**parse_command(char *str);
int     check_if_quotes_exist(char *str);
char    **handle_quotes(char *str);
void	alloc_word(char ***tab, char *s);
void	ft_count_words_with_quotes(char *s, int *words);
char    *get_one_word(char *s, int index, char c);
void    free_memory_and_update_count(char ***tab, int *count, int *i, int sign);

char	*get_path(char *cmd, char **ev);
int		count_tab(char **tab);
char	**join_array(char *element, char **tab);
void	execute_command(t_info *info, char **ev);
void	free_memory(t_info *info);
char	*get_command_path(char *ev, char *command);
void	close_fd(int *fd1, int *fd2);

#endif
