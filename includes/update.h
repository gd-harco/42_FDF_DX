#ifndef UPDATE_H
# define UPDATE_H
# include "nlx.h"

void	update_rotation(t_rot_info *rot);
void	update_translation(t_trans_info *trans);
void	update_projection(t_proj_info *proj, t_fdf *fdf);
void	update_world(t_world_i *world);
void	update_image(t_fdf *fdf_data);
#endif
