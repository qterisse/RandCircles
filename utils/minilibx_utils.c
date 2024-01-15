/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:34:25 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/15 12:44:47 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_canva *canva, int x, int y, int color)
{
	char	*dst;

	dst = canva->addr + (y * canva->line_length + x * (canva->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		key_bind(int key, t_canva *img)
{
	if (key == 65307 || key == 113)
		close_handler(img);
	return (0);
}

int	close_handler(t_canva *img)
{
	t_clist	*tmp;
	
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	while (img->circles)
	{
		tmp = img->circles->next;
		free(img->circles);
		img->circles = tmp;
	}
	free(img->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
