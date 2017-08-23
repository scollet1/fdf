/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 01:40:47 by scollet           #+#    #+#             */
/*   Updated: 2017/08/20 22:14:11 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define TITLE			"JoJo's Bizarre Adventure, now on the big screen"
# define HEIGHT 		720
# define WIDTH 			1080
# define CONTEXT1		10
# define CONTEXT2 		10
# define RELIEF 		-1

# define UP_ARROW 		126
# define DOWN_ARROW 	125
# define LEFT_ARROW 	123
# define RIGHT_ARROW	124
# define W 				13
# define S 				1
# define A 				0
# define D 				2
# define ESC 			53

typedef struct			s_vector
{
	float	x;
	float	y;
	float	z;
}						t_vector;

typedef struct			s_object
{
	int				id;
	t_vector		*vect_l;
	t_vector		*vect_m;
	int				x;
	int				y;
	int				zoom;
	int				relief;
	void			*mlx;
	void			*window;
	struct s_object	*next;
	struct s_object	*down;
}						t_object;

int						add_backsn(char *file);
t_object				*add_elem(float x, float y, float z, t_object *object);
t_object				*add_vector(t_object *object, int relief);
t_vector				*calculate(t_vector *vector, int relief);
int						color_gradient(double z);
void					draw(t_object *object, void *mlx, void *win);
int						error(const char *str);
t_object				*find_down(float x, float y, t_object *object);
t_object				*link_down(t_object *object);
void					print_line_a(double *coor, void *mlx, void *win);
void					print_line_b(double *coor, void *mlx,
						void *win, int act);
void					keypress_direction(t_object *object, int direction);
void					keypress_zoom(t_object *object, int zoom);
void					keypress_relief(t_object *object, int relief);
t_object				*reverse_list(t_object *object);
double					*set_grid_coor(t_object *object,
						int decb, int decd, int zoom);
t_object				*swap_list(t_object *object1, t_object *object2);
int						key_hook(int keypress, t_object *b);

#endif
