/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randcircles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:49:03 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/16 12:59:35 by quteriss         ###   ########.fr       */
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

int	get_max_size(int **circles, int x, int y)
{
	int		min_distance;
	int		distance;
	int		i;

	
	min_distance = MAX_CIRCLE_SIZE;
	if (!circles[0])
		return (min_distance);
	i = 0;
	while (circles[i])
	{
		distance = get_distance(x, y, circles[i][0], circles[i][1]) - (circles[i][2] + CIRCLE_MARGIN);
		printf("for (%d, %d), distance with (%d, %d) = %d\n", x, y, circles[i][0], circles[i][1], distance);
		if (distance < MIN_CIRCLE_SIZE) // on est dans un cercle existant ou un cercle de taille minimum croisera un cercle
			return (-1);
		if (distance < min_distance)
			min_distance = distance;
		i++;
	}
	return (min_distance);
}

void	generate_circle(t_canva *canva, int **circles, int *nb_circles)
{
	t_point	point;
	int		max_size;
	int		radius;

	point.x = ft_rand(
		WIN_PADDING + MIN_CIRCLE_SIZE, 
		WIN_WIDTH - (WIN_PADDING + MIN_CIRCLE_SIZE)
	);
	point.y = ft_rand(
		WIN_PADDING + MIN_CIRCLE_SIZE, 
		WIN_HEIGHT - (WIN_PADDING + MIN_CIRCLE_SIZE)
	);
	max_size = get_max_size(circles, point.x, point.y);
	if (max_size == -1)
		return ;
	radius = ft_rand(MIN_CIRCLE_SIZE, max_size);
	printf("radius = rand(%d, %d) = %d\n", MIN_CIRCLE_SIZE, max_size, radius);
	draw_filled_circle(canva, &point, radius, CIRCLE_COLOR);
	circles[*nb_circles] = malloc(sizeof(int) * 3);
	circles[*nb_circles][0] = point.x;
	circles[*nb_circles][1] = point.y;
	circles[*nb_circles][2] = radius;
	(*nb_circles)++;
}

int	main(void)
{
	int		**circles;
	int		i;
	t_canva	img;
	
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world");
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	
	circles = malloc(sizeof(int *) * (NBR_CIRCLES));
	if (!circles)
		return (1);
	i = 0;
	while (i < NBR_CIRCLES)
		circles[i++] = NULL;

	background(&img);
	mlx_hook(img.mlx_win, KeyPress, KeyPressMask, key_bind, &img);
	i = 0;
	while (i < NBR_CIRCLES)
		generate_circle(&img, circles, &i);

	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
