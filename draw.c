/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 06:04:09 by scollet           #+#    #+#             */
/*   Updated: 2017/08/20 22:00:54 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_a(int *grid, double *coor, void *mlx, void *win)
{
	grid[6] = grid[0] / 2;
	while (grid[7] <= grid[0])
	{
		grid[4] += grid[2];
		grid[6] += grid[1];
		if (grid[6] >= grid[0])
		{
			grid[6] -= grid[0];
			grid[5] += grid[3];
		}
		mlx_pixel_put(mlx, win, grid[4], grid[5],\
		color_gradient(coor[2]));
		grid[7]++;
	}
}

void	draw_b(int *grid, double *coor, void *mlx, void *win)
{
	grid[6] = grid[1] / 2;
	while (grid[7] <= grid[1])
	{
		grid[5] += grid[3];
		grid[6] += grid[0];
		if (grid[6] >= grid[1])
		{
			grid[6] -= grid[1];
			grid[4] += grid[2];
		}
		mlx_pixel_put(mlx, win, grid[4], grid[5],\
		color_gradient(coor[2]));
		grid[7]++;
	}
}

void	print_line_b(double *coor, void *mlx, void *win, int act)
{
	int *grid;

	if (act && (coor[3] = coor[6]))
		coor[4] = coor[7];
	grid = (int *)ft_memalloc(sizeof(int) * 8);
	grid[7] = 1;
	grid[4] = coor[0];
	grid[5] = coor[1];
	grid[0] = coor[3] - coor[0];
	grid[1] = coor[4] - coor[1];
	grid[2] = (grid[0] > 0) ? 1 : -1;
	grid[3] = (grid[1] > 0) ? 1 : -1;
	grid[0] = abs(grid[0]);
	grid[1] = abs(grid[1]);
	mlx_pixel_put(mlx, win, grid[4], grid[5], color_gradient(coor[2]));
	if (grid[0] > grid[1])
		draw_a(grid, coor, mlx, win);
	else
		draw_b(grid, coor, mlx, win);
}

void	draw(t_object *object, void *mlx, void *win)
{
	double		*coor;
	t_object	*tmp_object;
	int			dx;
	int			dy;

	tmp_object = object;
	dx = object->x;
	dy = object->y;
	while (tmp_object)
	{
		coor = set_grid_coor(tmp_object, dx, dy, object->zoom);
		if (tmp_object->next && tmp_object->vect_m->x <
				tmp_object->next->vect_m->x)
			print_line_b(coor, mlx, win, 0);
		if (tmp_object->down)
			print_line_b(coor, mlx, win, 1);
		tmp_object = tmp_object->next;
		free(coor);
	}
}
