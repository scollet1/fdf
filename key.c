/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 05:36:39 by scollet           #+#    #+#             */
/*   Updated: 2017/08/20 08:07:38 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keypress_direction(t_object *object, int direction)
{
	if (direction == 1)
	{
		object->x -= 15;
		mlx_clear_window(object->mlx, object->window);
		draw(object, object->mlx, object->window);
	}
	else if (direction == 2)
	{
		object->x += 15;
		mlx_clear_window(object->mlx, object->window);
		draw(object, object->mlx, object->window);
	}
	else if (direction == 3)
	{
		object->y += 15;
		mlx_clear_window(object->mlx, object->window);
		draw(object, object->mlx, object->window);
	}
	else if (direction == 4)
	{
		object->y -= 15;
		mlx_clear_window(object->mlx, object->window);
		draw(object, object->mlx, object->window);
	}
	return ;
}

void	keypress_zoom(t_object *object, int zoom)
{
	if (zoom)
	{
		object->zoom += 1;
		mlx_clear_window(object->mlx, object->window);
		draw(object, object->mlx, object->window);
	}
	else if (!zoom)
	{
		object->zoom -= 1;
		mlx_clear_window(object->mlx, object->window);
		draw(object, object->mlx, object->window);
	}
	return ;
}

void	keypress_relief(t_object *object, int relief)
{
	if (relief)
	{
		object->relief += 1;
		object = add_vector(object, object->relief);
		mlx_clear_window(object->mlx, object->window);
		draw(object, object->mlx, object->window);
		free(object->vect_m);
	}
	else if (!relief)
	{
		object->relief -= 1;
		object = add_vector(object, object->relief);
		mlx_clear_window(object->mlx, object->window);
		draw(object, object->mlx, object->window);
		free(object->vect_m);
	}
	return ;
}

int		key_hook(int key, t_object *object)
{
	if (key == 53)
	{
		mlx_destroy_window(object->mlx, object->window);
		exit(0);
	}
	if (key == UP_ARROW)
		keypress_direction(object, 1);
	else if (key == DOWN_ARROW)
		keypress_direction(object, 2);
	else if (key == RIGHT_ARROW)
		keypress_direction(object, 3);
	else if (key == LEFT_ARROW)
		keypress_direction(object, 4);
	else if (key == W)
		keypress_zoom(object, 1);
	else if (key == S)
		keypress_zoom(object, 0);
	else if (key == A)
		keypress_relief(object, 1);
	else if (key == D)
		keypress_relief(object, 0);
	else if (key == ESC)
		error("Thanks for playing!");
	return (0);
}
