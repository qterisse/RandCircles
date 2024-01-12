/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:32:33 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/12 17:09:16 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_abs(double nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

int	max(int	n1, int n2)
{
	if (n2 < n1)
		return (n1);
	return (n2);
}

int min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

int	ft_rand(int min, int max)
{
	double	n;
	n = rand();
	n /= 2147483647;
	n *= max;
	if (n < min)
		n += min;
	return ((int)n);
}