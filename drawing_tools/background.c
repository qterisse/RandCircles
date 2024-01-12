/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:25:53 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/12 17:28:30 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	background(t_canva *canva)
{
	int	x = 0;
	int	y;

	while (x <= WIN_WIDTH)
	{
		y = 0;
		while (y <= WIN_HEIGHT)
			put_pixel(canva, x, y++, BG_COLOR);
		x++;
	}
}
