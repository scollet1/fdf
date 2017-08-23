/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 01:36:40 by scollet           #+#    #+#             */
/*   Updated: 2017/08/20 08:04:13 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_object	*parse(char *line, t_object *object)
{
	char		**grid;
	int			x;
	static int	y = 0;

	grid = ft_strsplit(line, ' ');
	x = 0;
	while (grid[x] &&
		(object = add_elem(x, y, (float)ft_atoi(grid[x]), object)))
		free(grid[x++]);
	free(grid);
	y++;
	return (object);
}

void		run(t_object *object)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	object->relief = RELIEF;
	win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE);
	object = reverse_list(object);
	object = link_down(object);
	object = add_vector(object, object->relief);
	draw(object, mlx, win);
	object->window = win;
	object->mlx = mlx;
	object->x = 0;
	object->y = 0;
	mlx_key_hook(win, key_hook, object);
	mlx_loop(mlx);
}

int			main(int ac, char **av)
{
	int			fd;
	char		*line;
	t_object	*object;
	int			i;

	object = NULL;
	if (ac == 2 && add_backsn(av[1]))
	{
		fd = open(av[1], O_RDONLY);
		while ((i = get_next_line(fd, &line)))
		{
			if (i == 0 || i == -1)
				break ;
			object = parse(line, object);
			free(line);
		}
		run(object);
	}
	else
		error("Invalid input");
	return (0);
}
