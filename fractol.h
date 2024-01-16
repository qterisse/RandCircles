/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:11:11 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/16 13:03:36 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>

# define WIN_WIDTH  1000
# define WIN_HEIGHT 1000
# define WIN_PADDING 20

# define NBR_CIRCLES 80

# define MIN_CIRCLE_SIZE 30 // radius
# define MAX_CIRCLE_SIZE 80 // radius

# define CIRCLE_MARGIN 2

# define BG_COLOR 0xdfded7
# define MIDNIGHT_BLUE 0x191970
# define CIRCLE_COLOR MIDNIGHT_BLUE

typedef struct	s_canva {
	void	*img;
	char	*addr;
	void	*mlx_win;
	void	*mlx;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	struct s_clist	*circles;
}				t_canva;

typedef struct	s_point {
	double	x;
	double	y;
}				t_point;

typedef struct	s_clist
{
	struct s_clist	*next;
	int				*data; // [center_x, center_y, radius]
}				t_clist;

void	background(t_canva *canva);

void	draw_circle(t_canva *canva, t_point *point, int radius, int color);
void	draw_filled_circle(t_canva *canva, t_point *point, int radius, int color);

int		ft_abs(double nbr);
int		max(int	n1, int n2);
int		min(int n1, int n2);
int		ft_rand(int min, int max);

void	put_pixel(t_canva *canva, int x, int y, int color);
int		key_bind(int key, t_canva *img);
int		close_handler(t_canva *img);

void	free_points(t_point **points, int size);
t_point	*init_point(double x, double y);
int		inside_circle(t_point *center, int radius, int px, int py);

void	push_front(t_clist **clist, t_clist *new_elem);
t_clist *ft_new_elem(int data[3]);

#endif