#include <stdlib.h>
#include <string.h>
# include "../minilibx-linux/mlx.h"
# include "libft.h"
#include "math.h"

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
//	void	*img[256];

}			t_mlx;

typedef struct s_img
{
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
	int		win_height;
	int		win_width;
}			t_img;

typedef struct s_key
{
    int     s;
    int     w;
    int     d;
    int     a;
    int     q;
}   t_key;

typedef struct s_data
{
    char	**map;
	int		col_size;
	int		row_size;
	int		p_col;
	int		p_row;
	double player_x;
    double player_y;
    double player_dir;
    double player_speed;

    t_key   keys;
	t_img	img;
    t_mlx	*mlx;
}           t_data;


// init_map.c
void init_map(t_data *data);//fake valid data map, waiting for parsing
void    init_img(t_data *data);
void init_data(t_data *data);
// create_map.c
void draw_square(t_data *data, int x, int y, int size, int color);
void    draw_player(t_data *data);
int    do_frame(t_data *data);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void clear_image(t_data *data);
//end.c
void	ft_freetab(char **tab);
void destroy(t_data *data);
//move.c
int handle_keypress(int keycode, t_data *data);
void    draw_wall(t_data *data);
int key_press(int keycode, t_data *data);
int key_release(int keycode, t_data *data);
