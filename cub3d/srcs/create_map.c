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

	x = (int)data->player_x - 5;
	y = (int)data->player_y - 5;
	draw_square(data, x, y, 10, 0x00FF0000);
}

void clear_image(t_data *data)
{
	int x, y;

	for (y = 0; y < data->img.win_height; y++)
	{
		for (x = 0; x < data->img.win_width; x++)
		{
			my_mlx_pixel_put(data, x, y, 0x808080);
		}
	}
}

void    draw_wall(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->row_size)
	{
		x = 0;
		while (x < data->col_size)
		{
			if (data->map[y][x] == '1')
				draw_square(data, x * 64, y * 64, 64, 0x000000);
			x++;
		}
		y++;
	}
}

int    do_frame(t_data *data)
{
	handle_keypress(data);
	clear_image(data);
	draw_wall(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img.img_ptr, 0, 0);
	return (0);
}

