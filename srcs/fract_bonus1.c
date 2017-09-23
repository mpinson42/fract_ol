/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_bonus1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:24:25 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/07 19:32:44 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_frac_2(int x, int y, double tmp, t_gen *g)
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
		ft_putpixel_in_img(y, x, g, 0);
	else
		ft_putpixel_in_img(y, x, g, 42);
}

void	ft_frac1(t_gen *g)
{
	int		x;
	int		y;

	x = -1;
	g->image_x = (g->x2 - g->x1) * (g->zoom + 50);
	g->image_y = (g->y2 - g->y1) * (g->zoom + 10);
	ft_backgrond(g);
	while (++x < g->image_x + g->zoom)
	{
		y = -1;
		while (++y < g->image_y + g->zoom)
		{
			ft_frac_2(x, y, 0, g);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
}

void	ft_menu(t_gen *g)
{
	mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, "7,4,8,5,9,6 couleur");
	mlx_string_put(g->mlx, g->win, 0, 15, 0x00FFFFFF, "+/- iteration");
	mlx_string_put(g->mlx, g->win, 0, 30, 0x00FFFFFF, "fleche, deplacement");
	mlx_string_put(g->mlx, g->win, 0, 45, 0x00FFFFFF, "echap quiter");
	mlx_string_put(g->mlx, g->win, 0, 60, 0x00FFFFFF, "!/@/# changer fract");
	mlx_string_put(g->mlx, g->win, 0, 75, 0x00FFFFFF, "space stop julia");
}
