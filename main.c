/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 01:36:40 by scollet           #+#    #+#             */
/*   Updated: 2017/07/01 11:15:25 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_draw 	*set_mem(t_draw *object)
{
	ft_memset(&object, 0, sizeof(t_draw));
	ft_memset(&object->grid, 0, sizeof(t_grid));
	ft_memset(&object->grid->wire, 0, sizeof(t_wire));
	//ft_memset(&object->grid->wire->vector, 0, sizeof(t_vector));
	return (object);
}

int		main(int ac, char **av)
{
	t_draw *object;

	object = (t_draw*)ft_memalloc(sizeof(t_draw));
	object = set_mem(object);
	printf("%s\n", );
	if (ac < 2 && (object->err = (short)1))
		error(object->err);
	else
		control_fdf(object, av[1]);
	return (0);
}
