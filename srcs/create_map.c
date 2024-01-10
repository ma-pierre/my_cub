#include "cub.h"

void draw_square(t_data *data, int x, int y, int size, int color)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            my_mlx_pixel_put(data, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void    draw_player(t_data *data)
{
    int x;    
    int y;

    x = data->p_col * 64 + 32 - 5;
    y = data->p_row * 64 + 32 - 5;
    draw_square(data, x, y, 10, 0x00FF0000);
}

int    do_frame(t_data *data)
{
    draw_player(data);
    mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img.img_ptr, 0, 0);
    return (0);
}

