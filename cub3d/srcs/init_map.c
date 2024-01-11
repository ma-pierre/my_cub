
#include "cub.h"


void init_map(t_data *data)
{
	data->col_size = 25; 
	data->row_size = 9;

	data->map = (char **)malloc((data->row_size + 1) * sizeof(char *));
	for (int i = 0; i < data->row_size; i++) {
		data->map[i] = (char *)malloc((data->col_size + 1) * sizeof(char));
	}


	data->map[data->row_size] = NULL;

	char *map_lines[] = {
		"1111111111111111111111111",
		"1000100010001000100010001",
		"1010001010101010101010101",
		"1000100000000000000010001",
		"101011111000E000001010101",
		"1000100010100000100010001",
		"1010101010111010101010101",
		"1000000010000000100010001",
		"1111111111111111111111111"
	};

	for (int row = 0; row < data->row_size; row++) {
		strcpy(data->map[row], map_lines[row]);
		for (int col = 0; col < data->col_size; col++) {
			if (data->map[row][col] == 'E') {
				data->p_row = row;
				data->p_col = col;
			}
		}
	}
}

void init_data(t_data *data)
{
	data->player_x = data->p_col * 64 + 32;
	data->player_y = data->p_row * 64 + 32;
	data->player_dir = M_PI / 2;
	data->player_speed = 5;
}

void init_img(t_data *data)
{
	data->img.win_width = data->col_size * 64;
	data->img.win_height = data->row_size * 64;
	data->img.img_ptr = mlx_new_image(data->mlx->mlx, data->img.win_width, data->img.win_height);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
}

