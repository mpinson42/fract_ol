#include "fract.h"

void ft_menu(t_gen *g)
{
	mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, "7,4,8,5,9,6 couleur");
	mlx_string_put(g->mlx, g->win, 0, 15, 0x00FFFFFF, "+/- iteration");
	mlx_string_put(g->mlx, g->win, 0, 30, 0x00FFFFFF, "fleche, deplacement");
	mlx_string_put(g->mlx, g->win, 0, 45, 0x00FFFFFF, "echap quiter");

}

void	ft_mandel(t_gen *g)
{
	int x;
	int y;
	double tmp;

	g->x1 = -2.1;
	g->x2 = 0.6;
	g->y1 = -1.2;
	g->y2 = 1.2;
	g->zoom = 100;
	g->image_x = W;
	g->image_y = H;

	x = 0;
	g->zoom_x = g->image_x / (g->x2 - g->x1);
	g->zoom_y = g->image_y / (g->y2 - g->y1);
	ft_backgrond(g);
	while(x < g->image_x + 400)
	{
		y = - 200;
		while(y < g->image_y + 200)
		{
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
				ft_putpixel_in_img(x + g->x, y + g->y, g, 0);
			}
			else
				ft_putpixel_in_img(x + g->x, y + g->y, g, 0x00FFFFFF % (g->i * 0x00424242) / g->iter);
			y++;
		}
		x++;
	}
	//printf("%f\n", g->iter);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
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
	g->zoom = 200;
	g->image_x = W;
	g->image_y = H;

	x = 0;
	g->image_x = (g->x2 - g->x1) * (g->zoom + 50);
	g->image_y = (g->y2 - g->y1) * (g->zoom + 10);
	while(x < g->image_x)
	{
		y = 0;
		while(y < g->image_y)
		{
			
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
			{
				ft_putpixel_in_img(x, y, g, 0);
			}
			else
				ft_putpixel_in_img(x, y, g, 0x00FFFFFF % (g->i * 0x00424242) / g->iter);
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
		i = -1;
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
	g->zoom = 100;
	g->image_x = W;
	g->image_y = H;


	x = 0;
	//	g->image_x = (g->x2 - g->x1) * (g->zoom + 50);
	//	g->image_y = (g->y2 - g->y1) * (g->zoom + 10);
	ft_backgrond(g);
	while(x < g->image_x)
	{
		y =  -100;
		while(y < g->image_y)
		{
			g->c_r = x / g->zoom + g->x1;
			g->c_i = y / g->zoom + g->y1;
			g->z_r = 0;
			g->z_i = 0;
			g->i = 0;
			while (g->z_r * g->z_r + g->z_i * g->z_i < 4 && g->i < g->iter)
			{
				tmp = g->z_r;
				g->z_r = (g->z_r * g->z_r - g->z_i * g->z_i + g->c_r);
				g->z_i = 2 * fabs(g->z_i * tmp) + g->c_i;
				g->i++;
			}
			if (g->i == g->iter)
			{
				ft_putpixel_in_img(x + g->x, y  + g->y, g, 0);
			}
			else
				ft_putpixel_in_img(x + g->x, y + g->y, g, 0x00FFFFFF % (g->i * 0x00424242) / g->iter);
			y++;
		}
		x++;
	}
	//printf("%f\n", g->iter);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	//mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, ft_itoa(g->iter));
}