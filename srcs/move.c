#include "cub.h"

int handle_keypress(int keysym, t_data *data)
{
    if (keysym == 65307)
    {
       mlx_loop_end(data->mlx->mlx);
    }
    return (0);
}