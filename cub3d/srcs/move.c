#include "cub.h"

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == 65307)
        mlx_loop_end(data->mlx->mlx);
    if (keycode == 119)
    {
        data->player_x -= data->player_speed * cos(data->player_dir);
        data->player_y -= data->player_speed * sin(data->player_dir);
    }
    if (keycode == 115)
    {
        data->player_x += data->player_speed * cos(data->player_dir);
        data->player_y += data->player_speed * sin(data->player_dir);
    }
    if (keycode == 97)
        data->player_dir -= 0.1;
    if (keycode == 100)
        data->player_dir += 0.1;
    return (0);
}
//119=W 115=S 97=A 100=D
