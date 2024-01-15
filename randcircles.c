/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randcircles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:49:03 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/15 13:17:21 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_distance(int c1x, int c1y, int c2x, int c2y)
{
	int	dx;
	int	dy;

	dx = ft_abs(c1x - c2x);
	dy = ft_abs(c1y - c2y);
	return (sqrt((dx * dx) + (dy * dy)));
}

int	get_max_size(t_clist **circles, int x, int y)
{
	int		min_distance;
	int		distance;
	t_clist	*circle;

	
	min_distance = MAX_CIRCLE_SIZE;
	if (!circles)
		return (min_distance);
	circle = *circles;
	while (circle)
	{
		distance = get_distance(x, y, circle->data[0], circle->data[1]) - (circle->data[2] + CIRCLE_MARGIN);
		printf("for (%d, %d), distance with (%d, %d) = %d\n", x, y, circle->data[0], circle->data[1], distance);
		if (distance < MIN_CIRCLE_SIZE) // on est dans un cercle existant ou un cercle de taille minimum croisera un cercle
			return (-1);
		if (distance < min_distance)
			min_distance = distance;
		circle = circle->next;
	}
	return (min_distance);
}

void	generate_circle(t_canva *canva, int *nb_circles)
{
	t_point	point;
	int		max_size;
	int 	data_pouet[3];
	int		radius;

	point.x = ft_rand(
		WIN_PADDING + MIN_CIRCLE_SIZE, 
		WIN_WIDTH - (WIN_PADDING + MIN_CIRCLE_SIZE)
	);
	point.y = ft_rand(
		WIN_PADDING + MIN_CIRCLE_SIZE, 
		WIN_HEIGHT - (WIN_PADDING + MIN_CIRCLE_SIZE)
	);
	max_size = get_max_size(&(canva->circles), point.x, point.y);
	if (max_size == -1)
		return ;
	radius = ft_rand(MIN_CIRCLE_SIZE, max_size);
	draw_filled_circle(canva, &point, radius, CIRCLE_COLOR);
	data_pouet[0] = point.x;
	data_pouet[1] = point.y;
	data_pouet[2] = radius;
	push_front(&(canva->circles), ft_new_elem(data_pouet));
	(*nb_circles)++;
}

int	main(void)
{
	int		nb_circles;
	// t_clist	*circles;
	t_canva	img;
	
	img.circles = NULL;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world");
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);

	background(&img);
	mlx_hook(img.mlx_win, KeyPress, KeyPressMask, key_bind, &img);
	nb_circles = 0;
	while (nb_circles < 50)
		generate_circle(&img, &nb_circles);

	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
