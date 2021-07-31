/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:56:44 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/28 14:58:06 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int *fd1, int *fd2)
{
	close(*fd1);
	close(*fd2);
}

char	**join_array(char *element, char **tab)
{
	char	**result;
	int		count;
	int		i;

	count = count_tab(tab);
	count++;
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	result[i++] = ft_strdup(element);
	while (i < count)
	{
		result[i] = ft_strdup(tab[i - 1]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
