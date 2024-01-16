/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:32:33 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/16 12:59:27 by quteriss         ###   ########.fr       */
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

	if (max == min)
		return (max);
	n = min + (rand() % (max - min));
	return ((int)n);
}