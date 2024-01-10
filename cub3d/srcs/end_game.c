#include "cub.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void destroy(t_data *data)
{
     if (data->img.img_ptr)
        mlx_destroy_image(data->mlx->mlx, data->img.img_ptr);
    mlx_clear_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_display(data->mlx->mlx);
	ft_freetab(data->map);
	free(data->mlx->mlx);

}