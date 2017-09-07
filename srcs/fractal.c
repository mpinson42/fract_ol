/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:24:50 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/07 19:46:56 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_mandel_cal(int x, int y, double tmp, t_gen *g)
{
	g->c_r = x / g->zoom_x + g->x1;
	g->c_i = y / g->zoom_y + g->y1;
	g->z_r = 0;
	g->z_i = 0;
	g->i = 0;
	while (g->z_r * g->z_r + g->z_i * g->z_i < 4 && g->i < g->iter)
	{
		tmp = g->z_r;
		g->z_r = g->z_r * g->z_r - g->z_i * g->z_i + g->c_r;
		g->z_i = 2 * g->z_i * tmp + g->c_i;
		g->i++;
	}
	if (g->i == g->iter)
		ft_putpixel_in_img(x + g->x + g->s_x, y + g->y + g->s_y, g, 0);
	else
		ft_putpixel_in_img(x + g->x + g->s_x, y + g->y + g->s_y, g, 42);
}

void	ft_mandel(t_gen *g)
{
	int x;
	int y;

	x = -1;
	g->zoom_x = g->image_x / (g->x2 - g->x1) + g->zoom;
	g->zoom_y = g->image_y / (g->y2 - g->y1) + g->zoom;
	ft_backgrond(g);
	while (++x < g->image_x + 400 + g->zoom * 10)
	{
		y = -201;
		if (x + g->x + g->s_x > H || x + g->x + g->s_x < 0 || g->zoom_x == 0)
			continue ;
		while (++y < g->image_y + 200 + g->zoom * 10)
		{
			if (x + g->x + g->s_x > H || x + g->x + g->s_x < 0 ||
					y + g->y + g->s_y > W || y + g->y + g->s_y < 0 ||
					g->zoom_x + g->x1 == 0 || g->zoom_y + g->y1 == 0)
				continue ;
			ft_mandel_cal(x, y, 0, g);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
}

void	ft_julia_cal(int x, int y, double tmp, t_gen *g)
{
	g->z_r = x / (g->zoom + 50) + g->x1;
	g->z_i = y / (g->zoom + 10) + g->y1;
	g->i = 0;
	while (g->z_r * g->z_r + g->z_i * g->z_i < 4 && g->i < g->iter)
	{
		tmp = g->z_r;
		g->z_r = g->z_r * g->z_r - g->z_i * g->z_i + g->c_r;
		g->z_i = 2 * g->z_i * tmp + g->c_i;
		g->i++;
	}
	if (g->i == g->iter)
		ft_putpixel_in_img(x + g->s_x, y + g->s_y, g, 0);
	else
		ft_putpixel_in_img(x + g->s_x, y + g->s_y, g, 42);
}

void	ft_julia(t_gen *g)
{
	int x;
	int y;

	x = -201;
	g->image_x = (g->x2 - g->x1) * (g->zoom + 50);
	g->image_y = (g->y2 - g->y1) * (g->zoom + 10);
	ft_backgrond(g);
	while (++x < g->image_x + 400 + g->zoom * 10)
	{
		y = -201;
		if (x + g->s_x > H || x + g->s_x < 0)
			continue ;
		while (++y < g->image_y + 200 + g->zoom * 10)
		{
			if (x + g->s_x > H || x + g->s_x < 0 ||
				y + g->s_y > W || y + g->s_y < 0)
				continue ;
			ft_julia_cal(x, y, 0, g);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
}

void	ft_init_mandel(t_gen *g, int i)
{
	g->x1 = -2.1;
	g->x2 = 0.6;
	g->y1 = -1.2;
	g->y2 = 1.2;
	g->zoom = 1;
	g->image_x = W;
	g->image_y = H;
	g->nbr_fract = i;
	g->red = 198;
	g->green = 42;
	g->blue = 11;
	g->zoom_mou = 0;
	g->s_x = 0;
	g->s_y = 0;
	g->x = 0;
	g->y = 0;
	g->c_r = 0.285;
	g->c_i = 0.01;
	ft_mandel(g);
}
