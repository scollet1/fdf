/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:41:47 by scollet           #+#    #+#             */
/*   Updated: 2017/07/01 11:14:42 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
//#include "../includes/mlx.h"

int   animate(t_draw *object)
{
  object->img = mlx_new_image(object->mlx, WIND_X + 100, WIND_Y + 100);
  object->pxlimg = mlx_get_data_addr(object->img, &object->o,
                                    &object->grid->len, &object->d);
  draw(object);
  mlx_put_image_to_window(object->mlx, object->window, object->img, -50, -50);
  mlx_destroy_image(object->mlx, object->img);
  return (0);
}

/*
void  draw_point()
{

}

void  draw_wire(t_vector origin, t_vector dest, t_draw *object)
{
  if (outside(origin) && outside(dest))
    return ;
  pull_line(origin, dest, object->store);
  //origin.c = mlx_get_color_value(object->mlx, origin.c);
  //mlx_pixel_put(object->mlx, object->window, origin.x, y, origin.c);
  while (origin.x != dest.x && origin.y != dest.y)
  {
    //y = mx + b
    if (!outside(origin))
    {
      draw_point(origin, object, );
    }
    object->store[5] = object->store[4];
    if (object->store[5])

  }
  return ;
}

*/

t_draw   *draw(t_draw *object)
{
  int      x;
  int      y;
  t_vector origin;

  y = 0;
  while (y < object->grid->len)
  {
    x = 0;
    while (x < object->grid->wire[y]->len)
    {
      origin = *object->grid->wire[y]->vectors[x];
      if (object->grid->wire[y]->vectors[x + 1])
        mlx_pixel_put(object->mlx, object->window,
                    ((int)object->grid->wire[y]->vectors[x]->x),
                    ((int)object->grid->wire[y]->vectors[x + 1]->y), 1);
        //draw_wire(origin, (*object->grid->wire[y]->vectors[x + 1]), object);
      //if (object->grid->wire[y + 1])
        //if (object->grid->wire[y + 1]->vectors[x] &&
            //x <= object->grid->wire[y + 1]->len)
              //mlx_pixel_put();
              //draw_wire(origin, (*object->grid->wire[y + 1]->vectors[x], object);
    }
  }
  //mlx_pixel_put(object.mlx, object.window, object.grid->wire->x,
  //  object.grid->wire->y, object.grid->wire.c);
  return (object);
}

/*

t_draw   create_window(t_draw object)
{
  if ((object.window = mlx_new_window(object.mlx,
    WIND_X, WIND_Y, WIND_TITLE)) == NULL)
    error(ERR_STD);
  draw_object(object);
  return (object);
}

*/
