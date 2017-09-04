#include "fract.h"

#include <stdio.h>

void	ft_backgrond(t_gen *g)
{
	int i = 0;

	while(i < H * W * 4)
	{
		g->img_ptr[i] = g->red;
		g->img_ptr[i + 1] = g->blue;
		g->img_ptr[i + 2] = g->green;
		g->img_ptr[i + 3] = 0;
		i += 4;
	}
}

int		key_pressed(int kc, t_gen *g)
{
	(void)kc;
	(void)g;
	if(kc == 53)
		exit(0);
	if(kc == 69) //+
	{
		g->iter += 1;
	}
	if(kc == 78) // -
	{
		g->iter -= 1;
	}
	if (kc == 126)
		g->y -= 10;
	if (kc == 125)
		g->y += 10;
	if (kc == 123)
		g->x -= 10;
	if (kc == 124)
		g->x += 10;






	if(kc == 89)
		g->red++;
	if(kc == 86)
		g->red++;
	if(kc == 91)
		g->green++;
	if(kc == 87)
		g->green--;
	if(kc == 92)
		g->blue++;
	if(kc == 88)
	{
		g->blue--;
	}






	//printf("%d\n", kc);


	if(g->nbr_fract == 3)
		ft_burnnig(g);
	if(g->nbr_fract == 2)
		ft_julia(g);
	if(g->nbr_fract == 1)
		ft_mandel(g);
	printf("%d\n", g->blue);
	return (0);
}

int		red_cross(t_gen *g)
{
	(void)g;
	exit(0);
	return (0);
}