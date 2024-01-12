/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:33:37 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/12 15:59:36 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_points(t_point **points, int size)
{
	int	i;
	
	i = 0;
	while (i < size && points[i])
		free(points[i++]);
	free(points);
}

t_point	*init_point(double x, double y)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = (double) x;
	point->y = (double) y;
	return (point);
}

int	inside_circle(t_point *center, int radius, int px, int py)
{
	double	distance;
	double	dx;
	double	dy;

	dx = center->x - px;
	dy = center->y - py;
	distance = (dx * dx) + (dy * dy);
	return (distance <= radius * radius);
}
