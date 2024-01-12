/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:34:25 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/12 16:51:34 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_canva *canva, int x, int y, int color)
{
	char	*dst;

	dst = canva->addr + (y * canva->line_length + x * (canva->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
