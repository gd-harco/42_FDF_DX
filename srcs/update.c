#include "fdf.h"

void	update_rotation(t_rot_info *rot)
{
	free(rot->x_rot_m);
	free(rot->y_rot_m);
	free(rot->z_rot_m);
	rot->x_rot_m = get_x_rotation_matrix(rot->rot_x);
	rot->y_rot_m = get_y_rotation_matrix(rot->rot_y);
	rot->z_rot_m = get_z_rotation_matrix(rot->rot_z);
}

void	update_translation(t_trans_info *trans)
{
	free(trans->m);
	trans->m = get_translation_matrix(trans);
}

void	update_projection(t_proj_info *proj)
{
	free(proj->m);
	proj->m = get_projection_matrix(proj);
}

void	update_world(t_world_i *world)
{
	free(world->world_m);
	world->world_m = get_world_matrix(world);
}
