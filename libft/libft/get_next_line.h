/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:01:26 by scollet           #+#    #+#             */
/*   Updated: 2017/08/20 22:56:18 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# define FT_MAX_FD 4096
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);
char	*learn_to_read(const int fd, char **block, int *s);

#endif
