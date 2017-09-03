#include "fract.h"

#include <stdio.h>

void	ft_putpixel_in_img(int x, int y, t_gen *g, unsigned int color)
{
	if ((unsigned long long int)((x * 4) + (y * W * 4)) >
			(unsigned long long int)(W * H * 4) ||
			(unsigned long long int)((x * 4) + (y * W * 4))
			<= 0 || x > W || x < 0 || y < 0 || y > H)
		return ;
	if(color == 0)
	{
		g->img_ptr[(x * 4) + (y * W * 4)] = 0;
		g->img_ptr[(x * 4) + (y * W * 4) + 1] = 0;
		g->img_ptr[(x * 4) + (y * W * 4) + 2] = 0;
		g->img_ptr[(x * 4) + (y * W * 4) + 3] = 0;
	}
	else
	{
		g->img_ptr[(x * 4) + (y * W * 4)] = g->red * g->i;
		g->img_ptr[(x * 4) + (y * W * 4) + 1] = g->blue * g->i;
		g->img_ptr[(x * 4) + (y * W * 4) + 2] = g->green * g->i;
		g->img_ptr[(x * 4) + (y * W * 4) + 3] = 0;
	}
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
	g->red = 198;
	g->green = 42;
	g->blue = 11;

	x = 0;
	g->zoom_x = g->image_x / (g->x2 - g->x1);
	g->zoom_y = g->image_y / (g->y2 - g->y1);
	while(x < g->image_x)
	{
		y = 0;
		while(y < g->image_y)
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
	g->red = 198;
	g->green = 42;
	g->blue = 11;

	x = 0;
	g->image_x = (g->x2 - g->x1) * (g->zoom + 50);
	g->image_y = (g->y2 - g->y1) * (g->zoom + 10);
	while(x < g->image_x)
	{
		y = 0;
		while(y < g->image_y)
		{
			g->c_r = 0.285;
			g->c_i = 0.01;
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
	g->zoom = W / 4 + 14;
	g->image_x = W;
	g->image_y = H;
	g->red = 198;
	g->green = 42;
	g->blue = 11;


	x = 0;
	//	g->image_x = (g->x2 - g->x1) * (g->zoom + 50);
	//	g->image_y = (g->y2 - g->y1) * (g->zoom + 10);
	while(x < g->image_x)
	{
		y = 0;
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
	//mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, ft_itoa(g->iter));
}

int main(int argc, char **argv)
{
	t_gen g;

	ft_bzero(&g, sizeof(g));
	g.iter = 50;
	if(argc != 2)
		ft_putstr("./fractol [1](maelbrot) [2](julia) [3]buddhabrot");
	if (!(g.mlx = mlx_init()))
		return (-1);
	if (!(g.img = mlx_new_image(g.mlx, W, H)))
		return (-1);
	if (!(g.img_ptr = mlx_get_data_addr(g.img, &(g.bpp),
					&(g.s_l), &(g.endian))))
		return (-1);
	if (!(g.win = mlx_new_window(g.mlx, W, H, "fdf")))
		return (-1);

	if(argv[1][0] == '1' && argv[1][1] == 0)
		ft_mandel(&g);
	else if(argv[1][0] == '2' && argv[1][1] == 0)
		ft_julia(&g);
	else if(argv[1][0] == '3' && argv[1][1] == 0)
		ft_burnnig(&g);
	else
		ft_putstr("./fractol [1](maelbrot) [2]julia [3]buddhabrot");

	mlx_hook(g.win, 2, 1L << 0, &key_pressed, &g);
	mlx_hook(g.win, 17, (1L << 17), &red_cross, &g);
	mlx_loop(g.mlx);
}
