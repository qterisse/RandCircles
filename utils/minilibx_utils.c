/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:34:25 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/16 13:22:41 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_canva *canva, int x, int y, int color)
{
	char	*dst;

	dst = canva->addr + (y * canva->line_length + x * (canva->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	define_color(int key, t_canva *img)
{
	if (key == 48)
		img->color = MIDNIGHT_BLUE;
	else if (key == 49)
		img->color = JADE;
	else if (key == 50)
		img->color = IKB;
	else if (key == 51)
		img->color = ORANGE;
	else if (key == 52)
		img->color = BPURP;
	else if (key == 53)
		img->color = BLOOD;
	else if (key == 54)
		img->color = SALMON;
	else if (key == 55)
		img->color = GOLD;
	else if (key == 56)
		img->color = VEGAS;
	else if (key == 57)
		img->color = PASTEL_ORANGE;
}

int		key_bind(int key, t_canva *img)
{
	if (key == 65307 || key == 113)
		close_handler(img);
	else if (key >= 48 && key <= 57)
		define_color(key, img);
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
