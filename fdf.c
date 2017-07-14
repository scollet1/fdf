/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:41:47 by scollet           #+#    #+#             */
/*   Updated: 2017/07/01 11:15:15 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int   control_fdf(t_draw *object, char *arg)
{
  extract_coords(arg, object);
  object->mlx = mlx_init();
  //create_window(object);
  /*
  **  TODO :
  **    - ACCEPT INPUT
  */
  //mlx_key_hook(object->window, mlx_hook, object);
  mlx_expose_hook(object->window, animate, object);
  mlx_loop(object->mlx);
  return (0);
}
