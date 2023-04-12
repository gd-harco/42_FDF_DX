
#ifndef KEY_HANDLER_H
# define KEY_HANDLER_H

#include <X11/keysym.h>

//-----------------FUNCTIONS-----------------//
int		key_handler(int key, t_fdf *fdf_data);
int		exit_program(t_fdf *fdf_data);
void	translation(int key, t_fdf *fdf_data);
void	rotation(int key, t_fdf *fdf_data);
void	zoom(int key, t_fdf *fdf_data);
void	change_fov(int key, t_fdf *fdf_data);

#endif
