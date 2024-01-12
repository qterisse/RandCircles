/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:36:18 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/12 16:51:25 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_circle_pixels(t_canva *canva, t_point *p, t_point *rp, int color)
{
	put_pixel(canva, p->x + rp->x, p->y + rp->y, color);
	put_pixel(canva, p->x - rp->x, p->y + rp->y, color);
	put_pixel(canva, p->x + rp->x, p->y - rp->y, color);
	put_pixel(canva, p->x - rp->x, p->y - rp->y, color);
	put_pixel(canva, p->x + rp->y, p->y + rp->x, color);
	put_pixel(canva, p->x - rp->y, p->y + rp->x, color);
	put_pixel(canva, p->x + rp->y, p->y - rp->x, color);
	put_pixel(canva, p->x - rp->y, p->y - rp->x, color);
}

void	draw_circle(t_canva *canva, t_point *point, int radius, int color)
{
	t_point	*rp;
	int 	t;

	rp = init_point(radius, 0);
	if (!rp)
		return ;
	while (rp->x >= rp->y)
	{
		put_circle_pixels(canva, point, rp, color);
		rp->y = rp->y + 1;
		t += rp->y;
		if (t - rp->x >= 0)
		{
			t = t - rp->x;
			rp->x = rp->x - 1;
		}
	}
	free(rp);
}

void draw_filled_circle(t_canva *canva, t_point *point, int radius, int color)
{
	int	x;
	int	y;

	y = max(0, ceil(point->y - radius));
	while (y < min(floor(point->y + radius), WIN_HEIGHT))
	{
		x = max(0, ceil(point->x - radius));
		while (x < min(floor(point->x + radius), WIN_WIDTH))
		{
			if (inside_circle(point, radius, x, y))
				put_pixel(canva, x, y, color);
			x++;
		}
		y++;
	}
}
