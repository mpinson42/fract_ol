#ifndef FRACT_H
# define FRACT_H

# include "libft.h"
# include "mlx.h"
#include <math.h>
# define W 500
# define H 500

typedef	struct		s_gen
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*img_ptr;
	int				bpp;
	int				s_l;
	int				endian;


	double				iter;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double				zoom;
	double				image_x;
	double				image_y;
	double				zoom_y;
	double				zoom_x;



	double				c_r;
	double				c_i;
	double				c_r2;
	double				c_i2;
	double				z_r;
	double				z_i;

	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	int				i;
	int				x;
	int				y;
	int				nbr_fract;
}					t_gen;

int		key_pressed(int kc, t_gen *g);
int		red_cross(t_gen *g);
void	ft_mandel(t_gen *g);
void	ft_burnnig(t_gen *g);
void	ft_julia(t_gen *g);
void	ft_putpixel_in_img(int x, int y, t_gen *g, unsigned int color);
void	ft_backgrond(t_gen *g);

#endif