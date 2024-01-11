#include "cub.h"


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	static t_data	data = {0};
	static t_mlx	mlx = {0};

	
	data.mlx = &mlx;
	init_map(&data);
	init_data(&data);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, data.col_size * 64,
			data.row_size * 64, "cubEya+Marine");
	mlx_hook(mlx.win, 2, 1L<<0, handle_keypress, &data);
	init_img(&data);
	mlx_loop_hook(mlx.mlx, do_frame, &data);
	mlx_loop(mlx.mlx);
	destroy(&data);

	return (0);
}
