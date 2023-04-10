
#include "fdf.h"

int	key_handler(int key, t_fdf *fdf_data)
{
	if (key == XK_Escape || key == XK_q)
		exit_program(fdf_data);
//	else if (key == XK_Left || key == XK_Right
//		|| key == XK_Up || key == XK_Down)
//		translation(key, fdf_data);
//	else if (key == XK_a || key == XK_d
//		|| key == XK_w || key == XK_s)
//		rotation(key, fdf_data);
//	else if (key == XK_plus || key == XK_minus)
//		zoom(key, fdf_data);
	return (0);
}

int	exit_program(t_fdf *fdf_data)
{
	mlx_destroy_window(fdf_data->mlx_win->mlx, fdf_data->mlx_win->win_ptr);
	exit(0);
}
