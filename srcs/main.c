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
	printf("x = %d, y = %d\n", x, y);
	return (0);
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
	g.nbr_fract = argv[1][0] - '0';
		g.red = 198;
	g.green = 42;
	g.blue = 11;

	g.c_r = 0.285;
	g.c_i = 0.01;
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
	mlx_hook(g.win, 6, (1L<<6), &ft_mouse, &g);
	mlx_loop(g.mlx);
}
