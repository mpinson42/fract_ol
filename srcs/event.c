#include "fract.h"

#include <stdio.h>

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
	//printf("%d\n", kc);
	printf("%d", g->img_ptr[0]);
	ft_bzero(g->img_ptr, W * H * 4);
	ft_burnnig(g);
	printf("%d\n", kc);
	return (0);
}

int		red_cross(t_gen *g)
{
	(void)g;
	exit(0);
	return (0);
}