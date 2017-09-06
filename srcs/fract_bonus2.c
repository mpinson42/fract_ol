#include "fract.h"

void	ft_frac3(t_gen *g)
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
	ft_backgrond(g);
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
				ft_putpixel_in_img(x, y, g, 42);
			y++;
		}
		x++;
	}
	//printf("%f\n", g->iter);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
	//mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, ft_itoa(g->iter));
}

void ft_init_frac3(t_gen *g, int i)
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

	g->c_r = 0.382;
	g->c_i = 0.178;
	ft_frac3(g);
}

void	ft_frac4(t_gen *g)
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
	ft_backgrond(g);
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
				ft_putpixel_in_img(x, y, g, 42);
			y++;
		}
		x++;
	}
	//printf("%f\n", g->iter);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
	//mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, ft_itoa(g->iter));
}

void ft_init_frac4(t_gen *g, int i)
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

	g->c_r = 0.008;
	g->c_i = 0.688;
	ft_frac4(g);
}

void	ft_frac5(t_gen *g)
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
	ft_backgrond(g);
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
				ft_putpixel_in_img(x, y, g, 42);
			y++;
		}
		x++;
	}
	//printf("%f\n", g->iter);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
	//mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, ft_itoa(g->iter));
}

void ft_init_frac5(t_gen *g, int i)
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

	g->c_r = 0.252;
	g->c_i = 0.524;
	ft_frac5(g);
}