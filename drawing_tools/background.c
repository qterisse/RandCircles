/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:25:53 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/16 13:22:53 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	background(t_canva *canva)
{
	t_point p1;
	t_point p2;

	p1.x = 0;
	p1.y = 0;
	p2.x = WIN_WIDTH;
	p2.y = WIN_HEIGHT;
	draw_rectangle(canva, &p1, &p2, BG_COLOR);
}

void	borders(t_canva *canva)
{
	t_point p1;
	t_point p2;

	p1.x = 0;
	p1.y = 0;
	p2.x = WIN_PADDING;
	p2.y = WIN_HEIGHT;
	draw_rectangle(canva, &p1, &p2, BG_COLOR);
	p2.x = WIN_WIDTH;
	p2.y = WIN_PADDING;
	draw_rectangle(canva, &p1, &p2, BG_COLOR);
	p2.x = WIN_WIDTH;
	p2.y = WIN_HEIGHT;
	p1.x = WIN_WIDTH - WIN_PADDING;
	p1.y = 0;
	draw_rectangle(canva, &p1, &p2, BG_COLOR);
	p1.x = 0;
	p1.y = WIN_HEIGHT - WIN_PADDING;
	draw_rectangle(canva, &p1, &p2, BG_COLOR);
}

void	draw_rectangle(t_canva *canva, t_point *p1, t_point *p2, int color)
{
	int		x;
	int		y;
	int		dx;
	int		dy;

	y = 0;
	while (y < ft_abs(p2->y - p1->y))
	{
		x = 0;
		while (x < ft_abs(p2->x - p1->x))
		{
			dx = x;
			if (p2->x < p1->x)
				dx = -x;
			dy = y;
			if (p2->y < p1->y)
				dy = -y;
			put_pixel(canva, p1->x + dx, p1->y + dy, color);
			x++;
		}
		y++;
	}
}
