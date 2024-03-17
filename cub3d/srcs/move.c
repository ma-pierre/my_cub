#include "cub.h"

int key_press(int keycode, t_data *data)
{
    if (keycode == 's')
        data->keys.s = 1;
    if (keycode == 'd')
        data->keys.d = 1;
    if (keycode == 'a')
        data->keys.a = 1;
    if (keycode == 'w')
        data->keys.w = 1;
    if (keycode == 'q')
        data->keys.q = 1;
    if (keycode == 65361) // flèche gauche
        data->keys.l_arrow = 1;
    if (keycode == 65363) // flèche droite
        data->keys.r_arrow = 1;
    return (0);
}

int key_release(int keycode, t_data *data)
{
    if (keycode == 's')
        data->keys.s = 0;
    if (keycode == 'd')
        data->keys.d = 0;
    if (keycode == 'a')
        data->keys.a = 0;
    if (keycode == 'w')
        data->keys.w = 0;
    if (keycode == 'q')
        data->keys.q = 0;
    if (keycode == 65361) // flèche gauche
        data->keys.l_arrow = 0;
    if (keycode == 65363) // flèche droite
        data->keys.r_arrow = 0;
    return (0);
}

void handle_keypress(t_data *data)
{
    double  new_x;
	double  new_y;

	new_x = data->player_x;
	new_y = data->player_y;

	if (data->keys.q)
		mlx_loop_end(data->mlx->mlx);
	if (data->keys.w)
	{
		new_x -= data->player_speed * cos(data->player_dir);
		new_y -= data->player_speed * sin(data->player_dir);
	}
	if (data->keys.s)
	{
		new_x += data->player_speed * cos(data->player_dir);
		new_y += data->player_speed * sin(data->player_dir);
	}
	if (data->keys.d)
    {
        new_x += data->player_speed * sin(data->player_dir);
        new_y -= data->player_speed * cos(data->player_dir);
    }
    if (data->keys.a)
    {
        new_x -= data->player_speed * sin(data->player_dir);
        new_y += data->player_speed * cos(data->player_dir);
    }
	if (data->map[(int)(new_y / 64)][(int)(new_x / 64)] != '1')
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
	if (data->keys.l_arrow)
		data->player_dir -= 0.1;
	if (data->keys.r_arrow)
		data->player_dir += 0.1;
}