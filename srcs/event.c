/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:24:17 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/07 19:24:36 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_backgrond(t_gen *g)
{
	int i;

	i = 0;
	while (i < H * W * 4)
	{
		g->img_ptr[i] = g->red;
		g->img_ptr[i + 1] = g->blue;
		g->img_ptr[i + 2] = g->green;
		g->img_ptr[i + 3] = 0;
		i += 4;
	}
}

void	key_init(int kc, t_gen *g)
{
	if (kc == 18)
		ft_init_mandel(g, 1);
	if (kc == 19)
		ft_init_julia(g, 2);
	if (kc == 20)
		ft_init_burning(g, 3);
	if (kc == 21)
		ft_init_frac1(g, 4);
	if (kc == 22)
		ft_init_frac2(g, 5);
	if (kc == 23)
		ft_init_frac3(g, 6);
	if (kc == 26)
		ft_init_frac4(g, 7);
	if (kc == 28)
		ft_init_frac5(g, 8);
	if (kc == 117 && g->nbr_fract == 1)
		ft_init_mandel(g, 1);
	if (kc == 117 && g->nbr_fract == 2)
		ft_init_julia(g, 2);
	if (kc == 117 && g->nbr_fract == 3)
		ft_init_burning(g, 3);
	if (kc == 117 && (g->nbr_fract == 4 || g->nbr_fract == 5 ||
		g->nbr_fract == 6 || g->nbr_fract == 7 || g->nbr_fract == 8))
		ft_init_frac1(g, 4);
}

void	key_2(int kc, t_gen *g)
{
	if (kc == 78)
		g->iter -= 1;
	if (g->iter <= 0)
		g->iter = 1;
	if (kc == 126)
		g->y -= 10;
	if (kc == 125)
		g->y += 10;
	if (kc == 123)
		g->x -= 10;
	if (kc == 124)
		g->x += 10;
	if (kc == 89)
		g->red++;
	if (kc == 86)
		g->red++;
	if (kc == 91)
		g->green++;
	if (kc == 87)
		g->green--;
	if (kc == 92)
		g->blue++;
	if (kc == 88)
		g->blue--;
}

int		key_pressed(int kc, t_gen *g)
{
	if (kc == 50)
		bmp_write(g);
	if (kc == 53)
	{
		system("killall afplay");
		exit(0);
	}
	if (kc == 69)
		g->iter += 1;
	key_2(kc, g);
	key_init(kc, g);
	if (kc == 49 && g->space == 0)
		g->space = 1;
	else if (kc == 49 && g->space == 1)
		g->space = 0;
	if (g->nbr_fract == 3)
		ft_burnnig(g);
	if (g->nbr_fract == 2)
		ft_julia(g);
	if (g->nbr_fract == 1)
		ft_mandel(g);
	if (g->nbr_fract == 4 || g->nbr_fract == 5 ||
		g->nbr_fract == 6 || g->nbr_fract == 7 || g->nbr_fract == 8)
		ft_frac1(g);
	return (0);
}

int		red_cross(t_gen *g)
{
	(void)g;
	system("killall afplay");
	exit(0);
	return (0);
}
