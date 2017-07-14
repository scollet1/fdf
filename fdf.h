/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 01:40:47 by scollet           #+#    #+#             */
/*   Updated: 2017/06/27 08:00:22 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ERR_WRIN 	-1
# define ERR_STD    0
# define ERR_NOFILE 1
# define ERR_BADRET 2

# define WIND_TITLE "JUMBROTRON"
# define WIND_X     400 /* Windex */
# define WIND_Y     600 /* Windy */
# define FT         42  /* Ayy loma */

#include <unistd.h>
#include <fcntl.h>
#include "minilibx_macos/mlx.h"
#include "./libft/libft.h"

typedef struct s_vector
{
  double x;
  double y;
  double z;
  int    c;
}              t_vector;

typedef struct s_wire {
  t_vector **vectors;
  int      len;
}              t_wire;

typedef struct s_grid {
  t_wire **wire;
  int    len;
}              t_grid;

typedef struct s_draw
{
  t_grid    *grid;
  void      *mlx;
  void      *window;
  void      *img;
  void      *pxlimg;
  double    store[6];
  int       o;
  int       d;
  short     err;
}              t_draw;

int     animate(t_draw *object);
int     control_fdf(t_draw *object, char *arg);
t_draw  *create_window(t_draw *object);
t_draw  *draw(t_draw *object);
//void    draw_point(t_vector origin, t_vector dest, )
void    draw_wire(t_vector origin, t_vector dest, t_draw *object);
t_draw  *extract_coords(char *arg, t_draw *object);
int     error(short errcode);
int     getz(char *arr);
int     outside(t_vector vector);
void    pull_line(t_vector origin, t_vector dest, double *store);
t_draw  *set_mem(t_draw *object);

#endif
