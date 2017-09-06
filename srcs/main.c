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

int ft_mouse(int x, int y, t_gen *g)
{
	//(void)bouton;
	(void)x;
	(void)y;
	(void)g;
	double x_d = x;
	double y_d = y;

	//printf("x = %d, y = %d\n", x, y);
	if(x < 0 || x > H || y < 0 || y > W || g->nbr_fract != 2)
		return(0);







	while(y_d > 2)
		y_d = y_d / 500;
	while(x_d > 2)
		x_d = x_d / 500;
	g->c_r = x_d;
	g->c_i = y_d;
	ft_julia(g);
	printf("x = %f, y = %f\n", y_d, x_d);
//	printf("x = %d, y = %d\n", x, y);
	return (0);
}

int ft_clic(int button, int x,int y, t_gen *g)
{
	(void)g;
	//printf("bouton = %d x = %d y = %d\n", button, x, y);
	static double i = 0;
	if(button == 5 || button == 1) //+
	{
		g->zoom_mou += 50 * i;
		g->s_x -= (50 * i) * (x / 100);
		g->s_y -= (50 * i) * (y / 100);
		i += 0.5; 
	}
	if(button == 4 || button == 2)//-
	{
		g->zoom_mou -= 50 * i;
		g->s_x += (50 * i) * (x / 100);
		g->s_y += (50 * i) * (y / 100);
		i -= 0.5; 
	}
	if(g->nbr_fract == 1)
		ft_mandel(g);
	if(g->nbr_fract == 2)
		ft_julia(g);
	if(g->nbr_fract == 3)
		ft_burnnig(g);
	if(g->nbr_fract == 4)
		ft_frac1(g);
	if(g->nbr_fract == 5)
		ft_frac2(g);
	if(g->nbr_fract == 6)
		ft_frac3(g);
	if(g->nbr_fract == 7)
		ft_frac4(g);
	if(g->nbr_fract == 8)
		ft_frac5(g);
	return(0);
}

int main(int argc, char **argv)
{
	t_gen g;

	ft_bzero(&g, sizeof(g));
	g.iter = 50;
	if(argc != 2)
		ft_putstr("./fractol [1](maelbrot) [2](julia) [3]burning");
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
		ft_init_mandel(&g, argv[1][0] - '0');
	else if(argv[1][0] == '2' && argv[1][1] == 0)
		ft_init_julia(&g, argv[1][0] - '0');
	else if(argv[1][0] == '3' && argv[1][1] == 0)
		ft_init_burning(&g, argv[1][0] - '0');
	else if(argv[1][0] == '4' && argv[1][1] == 0)
		ft_init_frac1(&g, argv[1][0] - '0');
	else if(argv[1][0] == '5' && argv[1][1] == 0)
		ft_init_frac2(&g, argv[1][0] - '0');
	else if(argv[1][0] == '6' && argv[1][1] == 0)
		ft_init_frac3(&g, argv[1][0] - '0');
	else if(argv[1][0] == '7' && argv[1][1] == 0)
		ft_init_frac4(&g, argv[1][0] - '0');
	else if(argv[1][0] == '8' && argv[1][1] == 0)
		ft_init_frac5(&g, argv[1][0] - '0');
	else
	{
		ft_putstr("./fractol [1](maelbrot) [2]julia [3]burning");
		return(0);
	}

	mlx_hook(g.win, 2, 1L << 0, &key_pressed, &g);
	mlx_hook(g.win, 17, (1L << 17), &red_cross, &g);
	mlx_hook(g.win, 6, (1L<<6), &ft_mouse, &g);
	mlx_mouse_hook(g.win, &ft_clic, &g);
	mlx_loop(g.mlx);
}
