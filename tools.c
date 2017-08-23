/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 06:05:02 by scollet           #+#    #+#             */
/*   Updated: 2017/08/20 22:05:37 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			color_gradient(double z)
{
	if (z <= -10)
		return (0x00001047);
	else if (z <= -8)
		return (0x000F2268);
	else if (z <= -6)
		return (0x001A2974);
	else if (z <= -4)
		return (0x0025307F);
	else if (z <= -2)
		return (0x002A3485);
	else if (z <= -1)
		return (0x00353B91);
	else if (z <= 0)
		return (0x003B3F97);
	else if (z <= 1)
		return (0x003B3F97);
	else if (z <= 3)
		return (0x006164AA);
	else if (z <= 6)
		return (0x009A9CC8);
	else if (z <= 8)
		return (0x00D3D4E6);
	else
		return (0x00FFFFFF);
}

t_vector	*calculate(t_vector *vector, int relief)
{
	t_vector *new_vector;

	new_vector = (t_vector*)ft_memalloc(sizeof(t_vector));
	new_vector->x = (CONTEXT1 * vector->x) - (CONTEXT2 * vector->y);
	new_vector->y = (vector->z * relief) +
		((CONTEXT1 / 2) * vector->x) + ((CONTEXT2 / 2) * vector->y);
	return (new_vector);
}

t_object	*add_vector(t_object *object, int relief)
{
	t_object *tmp_object;

	tmp_object = object;
	while (tmp_object &&
	(tmp_object->vect_m = calculate(tmp_object->vect_l, relief)))
		tmp_object = tmp_object->next;
	return (object);
}

t_object	*add_elem(float x, float y, float z, t_object *object)
{
	t_object	*new_object;
	static int	i;

	new_object = (t_object *)ft_memalloc(sizeof(t_object));
	new_object->vect_l = (t_vector *)ft_memalloc(sizeof(t_vector));
	if (!object)
		new_object->next = NULL;
	else
		new_object->next = object;
	new_object->vect_l->x = x;
	new_object->vect_l->y = y;
	new_object->x = 1;
	new_object->y = 1;
	new_object->vect_l->z = z;
	new_object->zoom = 1;
	new_object->down = NULL;
	new_object->id = i++;
	return (new_object);
}

int			add_backsn(char *file)
{
	int fd;
	int save_ss;

	save_ss = dup(1);
	fd = open(file, O_APPEND | O_RDWR);
	if (fd == -1)
		return (0);
	dup2(fd, 1);
	ft_putstr("\n");
	dup2(save_ss, 1);
	close(fd);
	return (1);
}
