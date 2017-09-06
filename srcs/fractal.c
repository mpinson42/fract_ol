#include "fract.h"

#include <stdio.h>

void ft_menu(t_gen *g)
{
	mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, "7,4,8,5,9,6 couleur");
	mlx_string_put(g->mlx, g->win, 0, 15, 0x00FFFFFF, "+/- iteration");
	mlx_string_put(g->mlx, g->win, 0, 30, 0x00FFFFFF, "fleche, deplacement");
	mlx_string_put(g->mlx, g->win, 0, 45, 0x00FFFFFF, "echap quiter");
	mlx_string_put(g->mlx, g->win, 0, 60, 0x00FFFFFF, "!/@/# changer fract");
}

void	ft_mandel(t_gen *g)
{
	int x;
	int y;
	double tmp;

	x = 0;
	if((g->x2 - g->x1) + g->zoom_mou == 0 || (g->y2 - g->y1) + g->zoom_mou == 0)
	{
		g->zoom_mou++;
	}
	g->zoom_x = g->image_x / (g->x2 - g->x1) + g->zoom_mou;
	g->zoom_y = g->image_y / (g->y2 - g->y1) + g->zoom_mou;
	ft_backgrond(g);
	while(x < g->image_x + 400 + g->zoom_mou * 10)
	{
		y = - 200;
		if(x + g->x + g->s_x > H || x + g->x + g->s_x < 0 || g->zoom_x == 0)
			{
				x++;
				continue;
			}
		while(y < g->image_y + 200 + g->zoom_mou * 10)
		{
			if(x + g->x + g->s_x > H || x + g->x + g->s_x < 0 || y + g->y + g->s_y > W || y + g->y + g->s_y < 0 || g->zoom_x + g->x1 == 0 || g->zoom_y + g->y1 == 0)
			{
				y++;
				continue;
			}
			g->c_r = x / g->zoom_x + g->x1;
			g->c_i = y / g->zoom_y + g->y1;
			g->z_r = 0;
			g->z_i = 0;
			g->i = 0;
			
			while(g->z_r * g->z_r + g->z_i * g->z_i < 4 && g->i < g->iter)
			{
				tmp = g->z_r;
				g->z_r = g->z_r * g->z_r - g->z_i * g->z_i + g->c_r;
				g->z_i = 2 * g->z_i * tmp + g->c_i;
				g->i++;
			}
			if(g->i == g->iter)
			{
				ft_putpixel_in_img(x + g->x + g->s_x, y + g->y + g->s_y, g, 0);
			}
			else
				ft_putpixel_in_img(x + g->x + g->s_x, y + g->y + g->s_y, g, 0x00FFFFFF % (g->i * 0x00424242) / g->iter);
			y++;
		}
		x++;
	}
	//printf("%f\n", g->iter);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
	//mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, ft_itoa(g->iter));
}

void	ft_julia(t_gen *g)
{
	int x;
	int y;
	double tmp;

	g->x1 = -1;
	g->x2 = 1;
	g->y1 = -1.2;
	g->y2 = 1.2;
	g->zoom = 200 + g->zoom_mou;
	g->image_x = W;
	g->image_y = H;

	x = -200;
	g->image_x = (g->x2 - g->x1) * (g->zoom + 50);
	g->image_y = (g->y2 - g->y1) * (g->zoom + 10);
	ft_backgrond(g);
	while(x < g->image_x + 400 + g->zoom_mou * 10)
	{
		y = -200;
		if(x + g->s_x > H || x + g->s_x < 0)
		{
			x++;
			continue;
		}
		while(y < g->image_y + 200 + g->zoom_mou * 10)
		{
			if(x + g->s_x > H || x + g->s_x < 0 || y  + g->s_y > W || y + g->s_y < 0)
			{
				y++;
				continue;
			}
			g->z_r = x / (g->zoom + 50) + g->x1;
			g->z_i = y / (g->zoom + 10) + g->y1;;
			g->i = 0;

			while(g->z_r * g->z_r + g->z_i * g->z_i < 4 && g->i < g->iter)
			{
				tmp = g->z_r;
				g->z_r = g->z_r * g->z_r - g->z_i * g->z_i + g->c_r;
				g->z_i = 2 * g->z_i * tmp + g->c_i;
				g->i++;
			}
			if(g->i == g->iter)
				ft_putpixel_in_img(x + g->s_x, y + g->s_y, g, 0);
			else
				ft_putpixel_in_img(x + g->s_x, y + g->s_y, g, 42);
			y++;
		}
		x++;
	}
	//printf("%f\n", g->iter);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
	//mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, ft_itoa(g->iter));
}

float	ft_fabs(float i)
{
	if(i < 0)
		i = -i;
	return (i);
}

void	ft_burnnig(t_gen *g)
{
	int x;
	int y;
	double tmp;

	g->x1 = -2.1;
	g->x2 = 1.9;
	g->y1 = -1.5;
	g->y2 = 1;
	g->zoom = 100 + g->zoom_mou;
	g->image_x = W;
	g->image_y = H;


	x = 0;
	//	g->image_x = (g->x2 - g->x1) * (g->zoom + 50);
	//	g->image_y = (g->y2 - g->y1) * (g->zoom + 10);
	ft_backgrond(g);
	while(x < g->image_x + g->zoom_mou * 10)
	{
		if(x + g->x + g->s_x > H || x + g->x + g->s_x < 0)
			{
				x++;
				continue;
			}
		y =  -100;
		while(y < g->image_y + g->zoom_mou * 10 )
		{
			if(x + g->x + g->s_x > H || x + g->x + g->s_x < 0 || y + g->y + g->s_y > W || y + g->y + g->s_y < 0 || g->zoom_x + g->x1 == 0 || g->zoom_y + g->y1 == 0)
			{
				y++;
				continue;
			}
			g->c_r = x / g->zoom + g->x1;
			g->c_i = y / g->zoom + g->y1;
			g->z_r = 0;
			g->z_i = 0;
			g->i = 0;
			while (g->z_r * g->z_r + g->z_i * g->z_i < 4 && g->i < g->iter)
			{
				tmp = g->z_r;
				g->z_r = (g->z_r * g->z_r - g->z_i * g->z_i + g->c_r);
				g->z_i = 2 * ft_fabs(g->z_i * tmp) + g->c_i;
				g->i++;
			}
			if (g->i == g->iter)
			{
				ft_putpixel_in_img(x + g->x + g->s_x, y  + g->y + g->s_y, g, 0);
			}
			else
				ft_putpixel_in_img(x + g->x + g->s_x, y + g->y + g->s_y, g, 0x00FFFFFF % (g->i * 0x00424242) / g->iter);
			y++;
		}
		x++;
	}
	//printf("%f\n", g->iter);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
	//mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, ft_itoa(g->iter));
}

void ft_init_mandel(t_gen *g, int i)
{
	g->x1 = -2.1;
	g->x2 = 0.6;
	g->y1 = -1.2;
	g->y2 = 1.2;
	g->zoom = 100;
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

void ft_init_julia(t_gen *g, int i)
{
	g->x1 = -1;
	g->x2 = 1;
	g->y1 = -1.2;
	g->y2 = 1.2;
	g->zoom = 200;
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
	ft_julia(g);
}

void ft_init_burning(t_gen *g, int i)
{
	g->x1 = -2.1;
	g->x2 = 1.9;
	g->y1 = -1.5;
	g->y2 = 1;
	g->zoom = 100;
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
	ft_burnnig(g);
}