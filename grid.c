/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 06:04:47 by scollet           #+#    #+#             */
/*   Updated: 2017/08/20 21:58:42 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		*set_grid_coor(t_object *object, int decb, int decd, int zoom)
{
	double *tmp_coor;

	tmp_coor = (double *)ft_memalloc(sizeof(double) * 9);
	tmp_coor[0] = (object->vect_m->x + decd) * zoom;
	tmp_coor[1] = (object->vect_m->y + decb) * zoom;
	tmp_coor[2] = (double)object->vect_l->z;
	tmp_coor[3] = object->next ? ((object->next->vect_m->x + decd) * zoom) : 0;
	tmp_coor[4] = object->next ? (object->next->vect_m->y + decb) * zoom : 0;
	tmp_coor[5] = object->next ? (double)object->next->vect_m->z : 0;
	tmp_coor[6] = object->down ? ((object->down->vect_m->x + decd) * zoom) : 0;
	tmp_coor[7] = object->down ? (object->down->vect_m->y + decb) * zoom : 0;
	tmp_coor[8] = object->down ? (double)object->down->vect_m->z : 0;
	return (tmp_coor);
}

t_object	*find_down(float x, float y, t_object *object)
{
	t_object *tmp_object;

	tmp_object = object;
	while (tmp_object)
	{
		if (tmp_object->vect_l->x == x && tmp_object->vect_l->y == (y + 1))
			return (tmp_object);
		tmp_object = tmp_object->next;
	}
	return (NULL);
}

t_object	*link_down(t_object *object)
{
	t_object	*tmp_object;

	tmp_object = object;
	while (tmp_object)
	{
		tmp_object->down = find_down(tmp_object->vect_l->x,\
		tmp_object->vect_l->y, tmp_object->next);
		tmp_object = tmp_object->next;
	}
	return (object);
}

t_object	*swap_list(t_object *object1, t_object *object2)
{
	t_vector	*tmp_pt;
	int			tmp_id;

	tmp_id = object2->id;
	tmp_pt = object2->vect_l;
	object2->id = object1->id;
	object2->vect_l = object1->vect_l;
	object1->id = tmp_id;
	object1->vect_l = tmp_pt;
	return (object1);
}

t_object	*reverse_list(t_object *object)
{
	t_object	*tmp_object;
	int			reverse;

	reverse = 0;
	tmp_object = object;
	while (tmp_object->next)
	{
		if (tmp_object->id > tmp_object->next->id && (reverse = 1))
			tmp_object = swap_list(tmp_object, tmp_object->next);
		else
			tmp_object = tmp_object->next;
	}
	return (reverse ? reverse_list(object) : object);
}
