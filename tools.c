/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 17:36:00 by scollet           #+#    #+#             */
/*   Updated: 2017/07/07 17:36:01 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

double  absv(double num)
{
  return (num = (num < 0) ? num * -1 : num);
}

int   outside(t_vector vector)
{
  if (vector.x > WIND_X || vector.y > WIND_Y)
    return (1);
  return (0);
}

void  pull_line(t_vector origin, t_vector dest, double *store)
{
  store[0] = absv(origin.x - dest.x);
  store[1] = 0;
  store[2] = absv(origin.y - dest.y);
  store[3] = 0;
  store[4] = 0;
  store[5] = 0;
  return ;
}

int   getz(char *arr)
{
  int n;
  int sign;

  n = 0;
  sign = 1;
  if (arr[0] == '-')
    sign = -1;
  while (ft_isdigit(*arr))
    n = n * 10 + *arr++ - '0';
  return (n * sign);
}
