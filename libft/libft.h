/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:51:57 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/28 14:51:23 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
int		ft_count_words(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *str, size_t n);
char	*ft_strdup(const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_array(char ***arr);

#endif
