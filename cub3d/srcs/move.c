#include "cub.h"

int handle_keypress(int keycode, t_data *data)
{
    double  new_x;
    double  new_y;

    new_x = data->player_x;
    new_y = data->player_y;

    if (keycode == 65307)
        mlx_loop_end(data->mlx->mlx);

    if (keycode == 119)
    {
        new_x -= data->player_speed * cos(data->player_dir);
        new_y -= data->player_speed * sin(data->player_dir);
    }
    if (keycode == 115)
    {
        new_x += data->player_speed * cos(data->player_dir);
        new_y += data->player_speed * sin(data->player_dir);
    }

    if (data->map[(int)(new_y / 64)][(int)(new_x / 64)] != '1')
    {
        data->player_x = new_x;
        data->player_y = new_y;
    }

    if (keycode == 97)
        data->player_dir -= 0.1;
    if (keycode == 100)
        data->player_dir += 0.1;

    return (0);
}

//119=W 115=S 97=A 100=D
