/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 08:01:08 by scollet           #+#    #+#             */
/*   Updated: 2017/07/01 11:17:55 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int vector_map(char *line, int n, t_vector ***vectors)
{
  char     **arr;
  t_vector *vector;
  int      i;

  arr = ft_strsplit(line, ' ');
  i = 0;
  while (arr[i])
    ++i;
  *vectors = (t_vector**)ft_memalloc(sizeof(t_vector) * i);
  i = -1;
  while (arr[++i])
  {
    vector = (t_vector*)ft_memalloc(sizeof(t_vector));
    vector->x = i * WIND_X;
    vector->y = n * WIND_Y;
    vector->z = getz(arr[i]);
    vector->c = 1;
    *vectors[i] = vector;
  }
  return (i);
}

t_draw *extract_coords(char *arg, t_draw *object)
{
  char     *line;
  int      fd;
  int      n;
  t_vector **vectors;
  //t_wire   *wire;

  vectors = 0;//(t_vector**)ft_memalloc(sizeof(*t_vector));
  line = (char*)ft_memalloc(sizeof(char));
  fd = open(arg, O_RDONLY);
  n = 0;
  while (get_next_line(fd, &line))
  {
    object->grid->wire[n]->len = vector_map(line, n, &vectors);
    object->grid->wire[n]->vectors = vectors;
    //object->grid->wire[n] = wire;
    ++n;
  }
  object->grid->len = n;
  close(fd);
  return (object);
}
