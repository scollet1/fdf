/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 01:41:43 by scollet           #+#    #+#             */
/*   Updated: 2017/07/01 11:15:03 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int   error(short errcode)
{
  int   err;

  err = (int)errcode;
  ft_putstr_fd("Error, program failed with ERRCODE: ", 1);
  ft_putnbr(err);
  exit(err);
}
